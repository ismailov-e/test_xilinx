//-------------------------------------------------------------------------
// Contains modified versions of functions from video_frame_buffer.c.
//
//-------------------------------------------------------------------------

#include <stdio.h>

#include "xparameters.h"

#include "video_resolution.h"
#include "video_frame_buffer.h"
#include "xaxivdma.h"
#include "pixel.h"

///////////////////////////////////////////////////////////////////////////
// Modified version of vfb_rx_setup() to handle 32-bits per pixel,
// and to alternate between two rx frame buffers.
int vfb_rx_setup_for_demo(XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pWriteCfg,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 fb0,
                          Xuint32 fb1 )
{
	int Status;

	Xuint32 video_width, video_height;
	Xuint32 storage_width, storage_height, storage_stride, storage_size, storage_offset;

	// Get Video dimensions
	video_height = vres_get_height( uVideoResolution );      // in lines
	video_width  = vres_get_width ( uVideoResolution ) * sizeof(pixel); // in bytes // XXX

	// Get Storage dimensions
	storage_height = vres_get_height( uStorageResolution );      // in lines
	storage_width  = vres_get_width ( uStorageResolution ) * sizeof(pixel); // in bytes // XXX
	storage_stride = storage_width;
	storage_size   = storage_width * storage_height;
	storage_offset = ((storage_height-video_height)>>1)*storage_width +
		((storage_width-video_width)>>1);

	pWriteCfg->VertSizeInput = video_height;
	pWriteCfg->HoriSizeInput = video_width;
	pWriteCfg->Stride        = storage_stride;

	pWriteCfg->FrameDelay = 0;  /* This example does not test frame delay */

	pWriteCfg->EnableCircularBuf = 1;
	pWriteCfg->EnableSync = 1;

	pWriteCfg->PointNum = 1;
	pWriteCfg->EnableFrameCounter = 0; /* Endless transfers */

	pWriteCfg->FixedFrameStoreAddr = 0; /* We are not doing parking */

	Status = XAxiVdma_DmaConfig(pAxiVdma, XAXIVDMA_WRITE, pWriteCfg);
	if (Status != XST_SUCCESS) {
			xdbg_printf(XDBG_DEBUG_ERROR,
				"Write channel config failed %d\r\n", Status);

			return XST_FAILURE;
	}

	XAxiVdma_SetFrmStore(pAxiVdma, 2, XAXIVDMA_WRITE);

	pWriteCfg->FrameStoreStartAddr[0] = fb0;
	pWriteCfg->FrameStoreStartAddr[1] = fb1;

	/* Set the buffer addresses for transfer in the DMA engine
	 */
	Status = XAxiVdma_DmaSetBufferAddr(pAxiVdma,
	                                   XAXIVDMA_WRITE,
	                                   pWriteCfg->FrameStoreStartAddr);
	if (Status != XST_SUCCESS) {
		xdbg_printf(XDBG_DEBUG_ERROR,
		            "Write channel set buffer address failed %d\r\n", Status);
		return XST_FAILURE;
	}


	return XST_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////
// Modified version of vfb_rx_init() to handle cycling between two rx frame
// buffers.
int vfb_rx_init_for_demo( XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pWriteCfg,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 fb0,
                          Xuint32 fb1)
{
	int Status;

	/* Setup the write channel */
	Status = vfb_rx_setup_for_demo(pAxiVdma,
	                               pWriteCfg,
	                               uVideoResolution,
	                               uStorageResolution,
	                               fb0,
	                               fb1);
	if (Status != XST_SUCCESS) {
		xdbg_printf(XDBG_DEBUG_ERROR,
		            "Write channel setup failed %d\r\n", Status);

		return 1;
	}

	/* Start the DMA engine to transfer
	 */
	Status = vfb_rx_start(pAxiVdma);
	if (Status != XST_SUCCESS) {
		return 1;
	}

	XAxiVdma_FsyncSrcSelect(pAxiVdma, XAXIVDMA_S2MM_TUSER_FSYNC, XAXIVDMA_WRITE);

	return 0;
}

///////////////////////////////////////////////////////////////////////////
// Modified version of vfb_tx_setup_for_demo that handles 32-bits per pixel,
// uses park mode, and disables genlock.
int vfb_tx_setup_for_demo(XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pReadCfg,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 uMemAddr,
                          Xuint32 uNumFrames )
{
	int i;
	u32 Addr;
	int Status;

	Xuint32 video_width, video_height;
	Xuint32 storage_width, storage_height, storage_stride, storage_size, storage_offset;

	// Get Video dimensions
	video_height = vres_get_height( uVideoResolution );      // in lines
	video_width  = vres_get_width ( uVideoResolution ) * sizeof(pixel); // in bytes // XXX

	// Get Storage dimensions
	storage_height = vres_get_height( uStorageResolution );      // in lines
	storage_width  = vres_get_width ( uStorageResolution ) * sizeof(pixel); // in bytes // XXX
	storage_stride = storage_width;
	storage_size   = storage_width * storage_height;
	storage_offset = ((storage_height-video_height)>>1)*storage_width +
		((storage_width-video_width)>>1);

	pReadCfg->VertSizeInput = video_height;
	pReadCfg->HoriSizeInput = video_width;
	pReadCfg->Stride        = storage_stride;

	pReadCfg->FrameDelay = 0;  /* This example does not test frame delay */

	pReadCfg->EnableCircularBuf = 0; // XXX Park Mode.
	pReadCfg->EnableSync = 0; // XXX disable genlock

	pReadCfg->PointNum = 1;
	pReadCfg->EnableFrameCounter = 0; /* Endless transfers */

	pReadCfg->FixedFrameStoreAddr = 0;

	Status = XAxiVdma_DmaConfig(pAxiVdma, XAXIVDMA_READ, pReadCfg);
	if (Status != XST_SUCCESS) {
		xdbg_printf(XDBG_DEBUG_ERROR,
		            "Read channel config failed %d\n\r", Status);
		return XST_FAILURE;
	}

	/* Initialize buffer addresses
	 *
	 * These addresses are physical addresses
	 */
	Addr = uMemAddr + storage_offset;
	for(i = 0; i < uNumFrames; i++)
	{
		pReadCfg->FrameStoreStartAddr[i] = Addr;

		Addr += storage_size;
	}

	/* Set the buffer addresses for transfer in the DMA engine
	 * The buffer addresses are physical addresses
	 */
	Status = XAxiVdma_DmaSetBufferAddr(pAxiVdma, XAXIVDMA_READ,
			pReadCfg->FrameStoreStartAddr);
	if (Status != XST_SUCCESS) {
		xdbg_printf(XDBG_DEBUG_ERROR,
		            "Read channel set buffer address failed %d\n\r", Status);
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////
int vfb_tx_init_for_demo( XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pReadCfg,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 uMemAddr,
                          Xuint32 uNumFrames )
{
   int Status;

   /* Setup the read channel */
   Status = vfb_tx_setup_for_demo(pAxiVdma,
                                  pReadCfg,
                                  uVideoResolution,
                                  uStorageResolution,
                                  uMemAddr,
                                  uNumFrames);
   if (Status != XST_SUCCESS) {
	   xdbg_printf(XDBG_DEBUG_ERROR, "Read channel setup failed %d\n\r",
	               Status);
	   return XST_FAILURE;
   }

   /* Start the DMA engine to transfer
	*/
   Status = vfb_tx_start(pAxiVdma);
   if (Status != XST_SUCCESS) {
	   return XST_FAILURE;
   }

	return XST_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////
