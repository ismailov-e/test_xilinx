#include <stdio.h>

#include "demo.h"
#include "vbx_test.h"

#ifdef XPAR_INTC_0_DEVICE_ID
static XIntc Intc;
#else
static XScuGic Intc;
#endif

// VDMA s2mm interrupt counts
static int WriteDone;
static int WriteError;

static void WriteCallBack(void *CallbackRef, u32 Mask);
static void WriteErrorCallBack(void *CallbackRef, u32 Mask);

//volatile pixel *frame_buffer[VIDEO_BUFFERS];
//volatile int frame_ready = 0;

#define PERIODIC_STATS_ENABLE 1
#if PERIODIC_STATS_ENABLE
static int buf_switches = 0;
#endif

#define FRM_PTR_DEBUG 1
#if FRM_PTR_DEBUG
#define FRM_PTR_MAX_HISTORY 18
static int frm_ptr_array[FRM_PTR_MAX_HISTORY];
#endif

///////////////////////////////////////////////////////////////////////////
// Avnet FMC-IMAGEON EDID
Xuint8 fmc_imageon_hdmii_edid_content[256] =
{
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x06, 0xD4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x16, 0x01, 0x03, 0x81, 0x46, 0x27, 0x78,
		0x0A, 0x32, 0x30, 0xA1, 0x54, 0x52, 0x9E, 0x26,
		0x0A, 0x49, 0x4B, 0xA3, 0x08, 0x00, 0x81, 0xC0,
		0x81, 0x00, 0x81, 0x0F, 0x81, 0x40, 0x81, 0x80,
		0x95, 0x00, 0xB3, 0x00, 0x01, 0x01, 0x02, 0x3A,
		0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
		0x45, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x1E,
		0xA9, 0x1A, 0x00, 0xA0, 0x50, 0x00, 0x16, 0x30,
		0x30, 0x20, 0x37, 0x00, 0xC4, 0x8E, 0x21, 0x00,
		0x00, 0x1A, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x46,
		0x4D, 0x43, 0x2D, 0x49, 0x4D, 0x41, 0x47, 0x45,
		0x4F, 0x4E, 0x0A, 0x20, 0x00, 0x00, 0x00, 0xFD,
		0x00, 0x38, 0x4B, 0x20, 0x44, 0x11, 0x00, 0x0A,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x54,
		0x02, 0x03, 0x1F, 0x71, 0x4B, 0x90, 0x03, 0x04,
		0x05, 0x12, 0x13, 0x14, 0x1F, 0x20, 0x07, 0x16,
		0x26, 0x15, 0x07, 0x50, 0x09, 0x07, 0x01, 0x67,
		0x03, 0x0C, 0x00, 0x10, 0x00, 0x00, 0x1E, 0x01,
		0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E,
		0x28, 0x55, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00,
		0x1E, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16,
		0x20, 0x58, 0x2C, 0x25, 0x00, 0xC4, 0x8E, 0x21,
		0x00, 0x00, 0x9E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20,
		0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0xC4,
		0x8E, 0x21, 0x00, 0x00, 0x18, 0x01, 0x1D, 0x80,
		0x3E, 0x73, 0x38, 0x2D, 0x40, 0x7E, 0x2C, 0x45,
		0x80, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x1E, 0x1A,
		0x36, 0x80, 0xA0, 0x70, 0x38, 0x1F, 0x40, 0x30,
		0x20, 0x25, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00,
		0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};

// Dell ST2320L EDID
// Xuint8 fmc_imageon_hdmii_edid_content[256] =
Xuint8 dell_st2320l_edid[256] = {
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x10, 0xac, 0x24, 0xf0, 0x53, 0x41, 0x50, 0x48,
	0x2f, 0x15, 0x01, 0x03, 0x80, 0x33, 0x1d, 0x78,
	0xea, 0x1e, 0x55, 0xa0, 0x59, 0x56, 0x9f, 0x27,
	0x0d, 0x50, 0x54, 0xa5, 0x4b, 0x00, 0x71, 0x4f,
	0x81, 0x80, 0xd1, 0xc0, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3a,
	0x80, 0x18, 0x71, 0x38, 0x2d, 0x40, 0x58, 0x2c,
	0x45, 0x00, 0xfd, 0x1e, 0x11, 0x00, 0x00, 0x1e,
	0x00, 0x00, 0x00, 0xff, 0x00, 0x47, 0x52, 0x56,
	0x38, 0x56, 0x31, 0x42, 0x46, 0x48, 0x50, 0x41,
	0x53, 0x0a, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x44,
	0x45, 0x4c, 0x4c, 0x20, 0x53, 0x54, 0x32, 0x33,
	0x32, 0x30, 0x4c, 0x0a, 0x00, 0x00, 0x00, 0xfd,
	0x00, 0x38, 0x4c, 0x1e, 0x53, 0x11, 0x00, 0x0a,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xd4,

	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x10, 0xac, 0x24, 0xf0, 0x53, 0x41, 0x50, 0x48,
	0x2f, 0x15, 0x01, 0x03, 0x80, 0x33, 0x1d, 0x78,
	0xea, 0x1e, 0x55, 0xa0, 0x59, 0x56, 0x9f, 0x27,
	0x0d, 0x50, 0x54, 0xa5, 0x4b, 0x00, 0x71, 0x4f,
	0x81, 0x80, 0xd1, 0xc0, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3a,
	0x80, 0x18, 0x71, 0x38, 0x2d, 0x40, 0x58, 0x2c,
	0x45, 0x00, 0xfd, 0x1e, 0x11, 0x00, 0x00, 0x1e,
	0x00, 0x00, 0x00, 0xff, 0x00, 0x47, 0x52, 0x56,
	0x38, 0x56, 0x31, 0x42, 0x46, 0x48, 0x50, 0x41,
	0x53, 0x0a, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x44,
	0x45, 0x4c, 0x4c, 0x20, 0x53, 0x54, 0x32, 0x33,
	0x32, 0x30, 0x4c, 0x0a, 0x00, 0x00, 0x00, 0xfd,
	0x00, 0x38, 0x4c, 0x1e, 0x53, 0x11, 0x00, 0x0a,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xd4
};

///////////////////////////////////////////////////////////////////////////
/*
*
* This function setups the interrupt system so interrupts can occur for the
* DMA.  This function assumes INTC component exists in the hardware system.
*
* @param	AxiDmaPtr is a pointer to the instance of the DMA engine
*
* @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
*
* @note		None.
*
******************************************************************************/
static int SetupIntrSystem(XAxiVdma *AxiVdmaPtr)
{
	int Status;

	u32 WriteIntrId = WRITE_INTR_ID;

#ifdef XPAR_INTC_0_DEVICE_ID
	//////////////////////////////////////////////////////////////////////
	// MicroBlaze
	//////////////////////////////////////////////////////////////////////

	XIntc *IntcInstancePtr = &Intc;

	/* Initialize the interrupt controller and connect the ISRs */
	Status = XIntc_Initialize(IntcInstancePtr, INTC_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf( "Failed init intc\r\n");
		return XST_FAILURE;
	}

	Status = XIntc_Connect(IntcInstancePtr, WriteIntrId,
	         (XInterruptHandler)XAxiVdma_WriteIntrHandler, AxiVdmaPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed write channel connect intc %d\r\n", Status);
		return XST_FAILURE;
	}

	/* Start the interrupt controller */
	Status = XIntc_Start(IntcInstancePtr, XIN_REAL_MODE);
	if (Status != XST_SUCCESS) {
		xil_printf( "Failed to start intc\r\n");
		return XST_FAILURE;
	}

	/* Enable interrupts from the hardware */
	XIntc_Enable(IntcInstancePtr, WriteIntrId);

	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XIntc_InterruptHandler,
			(void *)IntcInstancePtr);

	Xil_ExceptionEnable();

#else
	//////////////////////////////////////////////////////////////////////
	// ARM Cortex-A9 in Zynq PS
	//////////////////////////////////////////////////////////////////////

	XScuGic *IntcInstancePtr = &Intc;
	XScuGic_Config *IntcConfig;

	// Initialize the interrupt controller driver so that it is ready to use.
	IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);
	if (NULL == IntcConfig) {
		return XST_FAILURE;
	}

	Status = XScuGic_CfgInitialize(IntcInstancePtr,
	                               IntcConfig,
	                               IntcConfig->CpuBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XScuGic_SetPriorityTriggerType(IntcInstancePtr, WriteIntrId, 0xA0, 0x3);

	/*
	 * Connect the device driver handler that will be called when an
	 * interrupt for the device occurs, the handler defined above performs
	 * the specific interrupt processing for the device.
	 */
	Status = XScuGic_Connect(IntcInstancePtr,
	                         WriteIntrId,
	                         (Xil_InterruptHandler) XAxiVdma_WriteIntrHandler,
	                         AxiVdmaPtr);
	if (Status != XST_SUCCESS) {
		return Status;
	}

	// Enable the interrupt for the DMA device.
	XScuGic_Enable(IntcInstancePtr, WriteIntrId);

	//////////////////////////////////////////////////////////////////////
	Xil_ExceptionInit();

	// Connect the interrupt controller interrupt handler to the hardware
	// interrupt handling logic in the processor.
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_IRQ_INT,
	                             (Xil_ExceptionHandler) XScuGic_InterruptHandler,
	                             IntcInstancePtr);

	// Enable interrupts in the Processor.
	Xil_ExceptionEnable();
#endif

	return XST_SUCCESS;
}

/*****************************************************************************/
/**
*
* This function disables the interrupts
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
static void DisableIntrSystem()
{
	u32 WriteIntrId = WRITE_INTR_ID;

#ifdef XPAR_INTC_0_DEVICE_ID
	XIntc *IntcInstancePtr = &Intc;

	XIntc_Disconnect(IntcInstancePtr, WriteIntrId);
#else
	XScuGic *IntcInstancePtr = &Intc;

	XScuGic_Disable(IntcInstancePtr, WriteIntrId);

	XScuGic_Disconnect(IntcInstancePtr, WriteIntrId);
#endif
}

/*****************************************************************************/
/*
 * Call back function for write channel
 *
 * This callback only clears the interrupts and updates the transfer status.
 *
 * @param	CallbackRef is the call back reference pointer
 * @param	Mask is the interrupt mask passed in from the driver
 *
 * @return	None
*
******************************************************************************/
#define XAXIVDMA_FRMPTR_STS_OFFSET 0x24
#define XAXIVDMA_S2MMFRMPTR_OUT_LSB 16
#define XAXIVDMA_S2MMFRMPTR_OUT_RMASK 0x1f

static void WriteCallBack(void *CallbackRef, u32 Mask)
{
	demo_t *pDemo = (demo_t *) CallbackRef;
	XAxiVdma *pAxiVdma = &(pDemo->vdma_hdmi);
	XAxiVdma_DmaSetup *pWriteCfg = &(pDemo->vdmacfg_hdmi_write);
	u32 reg;
	short frm_wr_idx;
	short frm_rdy_idx;
	pixel *temp;
	int Status;

	if (Mask & XAXIVDMA_IXR_FRMCNT_MASK) {
		// The most recent write frame (i.e. of the two available frame buffers,
		// the one not currently being written to) should be removed from the
		// set of buffers available to the frame writer and assigned to
		// frame_buffer[BUFFER_READY] for processing.
		//
		// The current frame_buffer[BUFFER_READY] should be added to the pair of
		// buffers that the frame writer can use.

		// Read S2MMFrmPtr_Out from FRMPTR_STS.
		// This is the frame currently being written to.
		reg = Xil_In32(pAxiVdma->BaseAddr + XAXIVDMA_FRMPTR_STS_OFFSET);
		frm_wr_idx = (reg >> XAXIVDMA_S2MMFRMPTR_OUT_LSB) & XAXIVDMA_S2MMFRMPTR_OUT_RMASK;
#if FRM_PTR_DEBUG
		if (WriteDone < FRM_PTR_MAX_HISTORY) {
			frm_ptr_array[WriteDone] = frm_wr_idx;
		}
#endif
#if 1
		frm_rdy_idx = !frm_wr_idx;

		temp = (pixel *) pDemo->buffer[BUFFER_READY];
		pDemo->buffer[BUFFER_READY] = (pixel *) pWriteCfg->FrameStoreStartAddr[frm_rdy_idx];
		pWriteCfg->FrameStoreStartAddr[frm_rdy_idx] = (Xuint32) temp;

		Status = XAxiVdma_DmaSetBufferAddr(pAxiVdma,
		                                   XAXIVDMA_WRITE,
		                                   pWriteCfg->FrameStoreStartAddr);
		Status = XAxiVdma_DmaStart(pAxiVdma, XAXIVDMA_WRITE);

		pDemo->frame_ready = 1;
#endif

		WriteDone++;
	}
}

///////////////////////////////////////////////////////////////////////////
void print_frm_ptr_array()
{
	int i;
	for (i = 0; i < FRM_PTR_MAX_HISTORY; i++) {
		xil_printf("%d ", frm_ptr_array[i]);
	}
	xil_printf("\r\n");
}

/*****************************************************************************/
/*
* Call back function for write channel error interrupt
*
* @param	CallbackRef is the call back reference pointer
* @param	Mask is the interrupt mask passed in from the driver
*
* @return	None
*
******************************************************************************/
static void WriteErrorCallBack(void *CallbackRef, u32 Mask)
{

	if (Mask & XAXIVDMA_IXR_ERROR_MASK) {
		WriteError += 1;
	}
}

///////////////////////////////////////////////////////////////////////////
void ssc_enable(fmc_imageon_t *imageon) {
	Xuint8 num_bytes;
	int i;
	Xuint8 iic_cdce913_ssc_on[3][2] = {{0x10, 0x6D}, // SSC = 011 (0.75%)
	                                   {0x11, 0xB6},
	                                   {0x12, 0xDB}};

   xil_printf( "Enabling spread-spectrum clocking (SSC)\n\r" );
   xil_printf( "\ttype=down-spread, amount=-0.75%%\n\r" );

   fmc_imageon_iic_mux( imageon, FMC_IMAGEON_I2C_SELECT_VID_CLK );

   for (i = 0; i < 3; i++) {
	   num_bytes = imageon->pIIC->fpIicWrite(imageon->pIIC,
	                                         FMC_IMAGEON_VID_CLK_ADDR,
	                                         (0x80 | iic_cdce913_ssc_on[i][0]),
	                                         &(iic_cdce913_ssc_on[i][1]),
	                                         1);
   }
}

///////////////////////////////////////////////////////////////////////////
void switch_buffers(demo_t *pDemo)
{
	pixel *temp;
	int Status;
    pixel **buffer = pDemo->buffer;
    XAxiVdma *pAxiVdma  = &(pDemo->vdma_hdmi);
    XAxiVdma_DmaSetup *pReadCfg = &(pDemo->vdmacfg_hdmi_read);


	// Tell frame reader to start using buffer[BUFFER_PROCESSING]
	// (which will be the new buffer[BUFFER_READING])
	pReadCfg->FrameStoreStartAddr[0] = (u32) buffer[BUFFER_PROCESSING];
	Status = XAxiVdma_DmaSetBufferAddr(pAxiVdma,
	                                   XAXIVDMA_READ,
	                                   pReadCfg->FrameStoreStartAddr);
	Status = XAxiVdma_DmaStart(pAxiVdma, XAXIVDMA_READ);

	// Wait for a new frame to become available.

	while (!pDemo->frame_ready) {
		usleep(100);
	}

	// Disable writer interrupts
#ifdef XPAR_INTC_0_DEVICE_ID
	XIntc_Disable(&Intc, WRITE_INTR_ID);
#else
	XScuGic_Disable(&Intc, WRITE_INTR_ID);
#endif

	// move buffer pointers
	temp = buffer[BUFFER_READING];
	buffer[BUFFER_READING]    = buffer[BUFFER_PROCESSING];
	buffer[BUFFER_PROCESSING] = buffer[BUFFER_READY];
	buffer[BUFFER_READY]      = temp;
	// clear frame_ready flag
	pDemo->frame_ready = 0;

	// Re-enable writer interrupts
#ifdef XPAR_INTC_0_DEVICE_ID
	XIntc_Enable(&Intc, WRITE_INTR_ID);
#else
	XScuGic_Enable(&Intc, WRITE_INTR_ID);
#endif

#if PERIODIC_STATS_ENABLE
	buf_switches++;
#endif
}

///////////////////////////////////////////////////////////////////////////
void mxp_init(vbx_mxp_t *vbx_mxp) {
	int status;

#if __MICROBLAZE__
	u16 mxp_dev_id = XPAR_VECTORBLOX_MXP_0_DEVICE_ID;
#else
	u16 mxp_dev_id = XPAR_VECTORBLOX_MXP_ARM_0_DEVICE_ID;
#endif

	status = VectorBlox_MXP_Initialize(vbx_mxp, mxp_dev_id);
	if (status != XST_SUCCESS) {
		xil_printf("ERROR: VectorBlox_MXP_Initialize failed.\n\r");
		VBX_FATAL(__LINE__, __FILE__, -1);
	}
}

///////////////////////////////////////////////////////////////////////////
#if XPAR_XTMRCTR_NUM_INSTANCES && !(__ARM_ARCH_7A__ && VBX_USE_A9_PMU_TIMER)
void timestamp_timer_init(XTmrCtr *timestamp_timer) {
	int status;

	u16 tmrctr_dev_id  = XPAR_TMRCTR_0_DEVICE_ID;
	u32 tmrctr_freq_hz = XPAR_TMRCTR_0_CLOCK_FREQ_HZ;

	status = XTmrCtr_Initialize(timestamp_timer, tmrctr_dev_id);
	if (XST_SUCCESS != status) {
		xil_printf("timestamp_timer_init failed!\n\r");
		return;
	}

	vbx_timestamp_init(timestamp_timer, tmrctr_freq_hz);
}
#else
void timestamp_timer_init() {
#if (__ARM_ARCH_7A__ && VBX_USE_A9_PMU_TIMER)
	u32 tmrctr_freq_hz = XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ/2;
	vbx_timestamp_init(tmrctr_freq_hz);
#endif
}
#endif

///////////////////////////////////////////////////////////////////////////
void buttons_init(XGpio *buttons) {

	int status;

	status = XGpio_Initialize(buttons, XPAR_BTNS_5BITS_DEVICE_ID);
	if (XST_SUCCESS != status) {
		xil_printf("button_init failed!\n\r");
		return;
	}

	// Set the five Channel 1 bits to be inputs (1)
	XGpio_SetDataDirection(buttons, 1, 0x1f);
}

///////////////////////////////////////////////////////////////////////////
void slide_switches_init(XGpio *slide_switches) {

	int status;

	status = XGpio_Initialize(slide_switches, XPAR_SWS_8BITS_DEVICE_ID);
	if (XST_SUCCESS != status) {
		xil_printf("slide_switches_init failed!\n\r");
		return;
	}

	// Set the eight Channel 1 bits to be inputs (1)
	XGpio_SetDataDirection(slide_switches, 1, 0xff);
}


///////////////////////////////////////////////////////////////////////////
// GPIO bitmasks for buttons.
#define BTNU 0x10
#define BTNR 0x08
#define BTNL 0x04
#define BTND 0x02
#define BTNC 0x01

// button = XGpio_DiscreteRead(&(pDemo->buttons), 1);

///////////////////////////////////////////////////////////////////////////
int init_demo( demo_t *pDemo)
{
    pDemo->uBaseAddr_IIC_FmcImageon       = XPAR_FMC_IMAGEON_IIC_0_BASEADDR;

#if defined(XPAR_XVTC_NUM_INSTANCES)
#if defined(XPAR_V_TC_0_DEVICE_ID)
    pDemo->uDeviceId_VTC_HdmiiDetector    = XPAR_V_TC_0_DEVICE_ID;
#endif
#if defined(XPAR_V_TC_1_DEVICE_ID)
    pDemo->uDeviceId_VTC_HdmioGenerator   = XPAR_V_TC_1_DEVICE_ID;
#endif
#endif
    pDemo->uDeviceId_VDMA_HdmiFrameBuffer = XPAR_AXI_VDMA_0_DEVICE_ID;
    pDemo->uBaseAddr_MEM_HdmiFrameBuffer  = 0x10000000;
    pDemo->uNumFrames_HdmiFrameBuffer     = XPAR_AXIVDMA_0_NUM_FSTORES;
    pDemo->bVerbose = 1;

	int ret;
	Xuint32 timeout = 100;
	Xuint32 iterations = 0;
	int i;

	WriteDone = 0;
	WriteError = 0;
#if FRM_PTR_DEBUG
	for (i = 0; i < FRM_PTR_MAX_HISTORY; i++) {
		frm_ptr_array[i] = 0;
	}
#endif

#if __ARM_ARCH_7A__
	vbx_zynq_remap_ddr_uncached();
#if VBX_USE_AXI_INSTR_PORT_NORMAL_MEMORY
	vbx_zynq_set_instr_port_normal_uncached();
#elif VBX_USE_AXI_INSTR_PORT_DEVICE_MEMORY
	vbx_zynq_set_instr_port_device_memory();
#endif
#endif // __ARM_ARCH_7A__

#if XPAR_XTMRCTR_NUM_INSTANCES && !VBX_USE_A9_PMU_TIMER
	timestamp_timer_init(&(pDemo->timestamp_timer));
#else
	timestamp_timer_init();
#endif
	slide_switches_init(&(pDemo->slide_switches));
	buttons_init(&(pDemo->buttons));
	mxp_init(&(pDemo->vbx_mxp));

	xil_printf("\n\r");
	xil_printf("------------------------------------------------------\n\r");
	xil_printf("--       FMC-IMAGEON HDMI Video Frame Buffer        --\n\r");
	xil_printf("------------------------------------------------------\n\r");
	xil_printf("\n\r");

	xil_printf( "FMC-IMAGEON Initialization ...\n\r" );

	ret = fmc_iic_xps_init(&(pDemo->fmc_imageon_iic),
	                       "FMC-IMAGEON I2C Controller",
	                       pDemo->uBaseAddr_IIC_FmcImageon );
	if (!ret) {
		xil_printf( "ERROR : Failed to open FMC-IIC driver\n\r" );
		return XST_FAILURE;
	}

	fmc_imageon_init(&(pDemo->fmc_imageon), "FMC-IMAGEON", &(pDemo->fmc_imageon_iic));
	pDemo->fmc_imageon.bVerbose = pDemo->bVerbose;

	///////////////////////////////////////////////////////////////////////////
	// Configure Video Clock Synthesizer
	xil_printf( "Video Clock Synthesizer Configuration ...\n\r" );
	fmc_imageon_vclk_init( &(pDemo->fmc_imageon) );
	fmc_imageon_vclk_config( &(pDemo->fmc_imageon), FMC_IMAGEON_VCLK_FREQ_148_500_000);

	///////////////////////////////////////////////////////////////////////////
	// Initialize HDMI Input (including EDID content)
	xil_printf( "HDMI Input Initialization ...\n\r" );
	ret = fmc_imageon_hdmii_init( &(pDemo->fmc_imageon),
	                              1, // hdmiiEnable = 1
	                              1, // editInit = 1
	                              fmc_imageon_hdmii_edid_content
	                              );
	if ( !ret ) {
		xil_printf( "ERROR : Failed to init HDMI Input Interface\n\r" );
		return XST_FAILURE;
	}

	///////////////////////////////////////////////////////////////////////////
#if 1
	ssc_enable(&(pDemo->fmc_imageon));
#endif

	///////////////////////////////////////////////////////////////////////////
	// Set HDMI output to 1080P60 resolution
	pDemo->hdmio_resolution = VIDEO_RESOLUTION_1080P;
	pDemo->hdmio_width  = 1920;
	pDemo->hdmio_height = 1080;

	//pDemo->hdmio_timing.IsHDMI        = 1; // HDMI Mode
	pDemo->hdmio_timing.IsHDMI        = 0; // DVI Mode
	pDemo->hdmio_timing.IsEncrypted   = 0;
	pDemo->hdmio_timing.IsInterlaced  = 0;
	pDemo->hdmio_timing.ColorDepth    = 8;

	pDemo->hdmio_timing.HActiveVideo  = 1920;
	pDemo->hdmio_timing.HFrontPorch   =   88;
	pDemo->hdmio_timing.HSyncWidth    =   44;
	pDemo->hdmio_timing.HSyncPolarity =    1;
	pDemo->hdmio_timing.HBackPorch    =  148;

	pDemo->hdmio_timing.VActiveVideo  = 1080;
	pDemo->hdmio_timing.VFrontPorch   =    4;
	pDemo->hdmio_timing.VSyncWidth    =    5;
	pDemo->hdmio_timing.VSyncPolarity =    1;
	pDemo->hdmio_timing.VBackPorch    =   36;

	xil_printf( "HDMI Output Initialization ...\n\r" );
	ret = fmc_imageon_hdmio_init( &(pDemo->fmc_imageon),
	                              1,                      // hdmioEnable = 1
	                              &(pDemo->hdmio_timing), // pTiming
	                              0                       // waitHPD = 0
	                              );
	if ( !ret ) {
		xil_printf( "ERROR : Failed to init HDMI Output Interface\n\r" );
		return XST_FAILURE;
	}

    pDemo->buffer = (pixel **)malloc(sizeof(pixel*)*VIDEO_BUFFERS);
	///////////////////////////////////////////////////////////////////////////
	for (i = 0; i < VIDEO_BUFFERS; i++) {
		pDemo->buffer[i] = (pixel *) (pDemo->uBaseAddr_MEM_HdmiFrameBuffer + \
		                             i*IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel));
	}
	for (i = 0; i < VIDEO_BUFFERS; i++) {
		xil_printf("frame_buffer[%d] = 0x%08x\n\r", i, (unsigned int) pDemo->buffer[i]);
	}

    pDemo->short_buffer = (short *) (pDemo->buffer[VIDEO_BUFFERS-1] +
                              IMAGE_WIDTH*IMAGE_HEIGHT);

    pDemo->frame_ready=0;

	///////////////////////////////////////////////////////////////////////////
	// Initialize Output Side of AXI VDMA
	xil_printf( "Video DMA (Output Side) Initialization ...\n\r" );
	vfb_common_init(
	                pDemo->uDeviceId_VDMA_HdmiFrameBuffer, // uDeviceId
	                &(pDemo->vdma_hdmi)                    // pAxiVdma
	                );
	vfb_tx_init_for_demo(
	            &(pDemo->vdma_hdmi),                    // pAxiVdma
	            &(pDemo->vdmacfg_hdmi_read),            // pReadCfg
	            pDemo->hdmio_resolution,                // uVideoResolution
	            pDemo->hdmio_resolution,                // uStorageResolution
	            (Xuint32) pDemo->buffer[BUFFER_READING], // uMemAddr
	            1                                       // uNumFrames
	            );

	///////////////////////////////////////////////////////////////////////////
	// Configure VTC generator on output data path
	// (If it is configurable, i.e. was instantiated with AXI4Lite interface)
#if defined(XPAR_XVTC_NUM_INSTANCES) && defined(XPAR_V_TC_1_DEVICE_ID)
	xil_printf( "Video Timing Controller (generator) Initialization ...\n\r" );
	vgen_init( &(pDemo->vtc_hdmio_generator), pDemo->uDeviceId_VTC_HdmioGenerator );
	vgen_config( &(pDemo->vtc_hdmio_generator), pDemo->hdmio_resolution, 1 );
#endif

	///////////////////////////////////////////////////////////////////////////
	// Interrupt Controller init
	ret = SetupIntrSystem(&(pDemo->vdma_hdmi));
	if (XST_SUCCESS != ret) {
		xil_printf("Setup interrupt system failed\r\n");
		return XST_FAILURE;
	}

	///////////////////////////////////////////////////////////////////////////
	XAxiVdma_SetCallBack(&(pDemo->vdma_hdmi), // InstancePtr
	                     XAXIVDMA_HANDLER_GENERAL, // HandlerType
	                     WriteCallBack, // CallBackFunc
	                     (void *) pDemo, // CallBackRef
	                     XAXIVDMA_WRITE);  // Direction

	XAxiVdma_SetCallBack(&(pDemo->vdma_hdmi),
	                     XAXIVDMA_HANDLER_ERROR,
	                     WriteErrorCallBack,
	                     (void *) pDemo,
	                     XAXIVDMA_WRITE);

	XAxiVdma_IntrEnable(&(pDemo->vdma_hdmi), XAXIVDMA_IXR_ALL_MASK, XAXIVDMA_WRITE);

	///////////////////////////////////////////////////////////////////////////
#if 0
	i = 0;
	while(1) {
		sleep(5);
		printf("%d\n", i);
		i += 1;
	}
#endif

	/////////////////////////////////////////////////////////////////////////////////
	while (1) {
		if ( iterations > 0 ) {
			xil_printf( "\n\rPress ENTER to re-start ...\n\r" );
			getchar();
			// XXX When the target is MicroBlaze, this getchar only works
			// with the MicroBlaze MDM UART, not with the PS7 UART.
		}
	   iterations++;

	   //////////////////////////////////////////////////////////////////////
	   xil_printf( "Waiting for ADV7611 to locked on incoming video ...\n\r" );
	   pDemo->hdmii_locked = 0;
	   timeout = 100;
	   while ( !(pDemo->hdmii_locked) && timeout-- ) {
		   usleep(100000); // wait 100msec ...
		   pDemo->hdmii_locked = fmc_imageon_hdmii_get_lock( &(pDemo->fmc_imageon) );
	   }
	   if ( !(pDemo->hdmii_locked) ) {
		   xil_printf( "\tERROR : ADV7611 has NOT locked on incoming video, aborting !\n\r" );
		   //return -1;
		   continue;
	   }
	   xil_printf( "\tADV7611 Video Input LOCKED\n\r" );
	   usleep(100000); // wait 100msec for timing to stabilize

	   //////////////////////////////////////////////////////////////////////
	   // Get Video Input information
	   fmc_imageon_hdmii_get_timing( &(pDemo->fmc_imageon), &(pDemo->hdmii_timing) );
	   pDemo->hdmii_width  = pDemo->hdmii_timing.HActiveVideo;
	   pDemo->hdmii_height = pDemo->hdmii_timing.VActiveVideo;
	   pDemo->hdmii_resolution = vres_detect( pDemo->hdmii_width, pDemo->hdmii_height );

	   xil_printf( "ADV7611 Video Input Information\n\r" );
	   xil_printf("\tVideo Input      = %s", pDemo->hdmii_timing.IsHDMI ? "HDMI" : "DVI" );
	   xil_printf("%s", pDemo->hdmii_timing.IsEncrypted ? ", HDCP Encrypted" : "" );
	   xil_printf(", %s\n\r", pDemo->hdmii_timing.IsInterlaced ? "Interlaced" : "Progressive" );
	   xil_printf("\tColor Depth      = %d bits per channel\n\r",
	              (int) pDemo->hdmii_timing.ColorDepth );
	   xil_printf("\tHSYNC Timing     = hav=%04d, hfp=%02d, hsw=%02d(hsp=%d), hbp=%03d\n\r",
	              (int) pDemo->hdmii_timing.HActiveVideo,
	              (int) pDemo->hdmii_timing.HFrontPorch,
	              (int) pDemo->hdmii_timing.HSyncWidth,
	              (int) pDemo->hdmii_timing.HSyncPolarity,
	              (int) pDemo->hdmii_timing.HBackPorch
	              );
	   xil_printf("\tVSYNC Timing     = vav=%04d, vfp=%02d, vsw=%02d(vsp=%d), vbp=%03d\n\r",
	              (int) pDemo->hdmii_timing.VActiveVideo,
	              (int) pDemo->hdmii_timing.VFrontPorch,
	              (int) pDemo->hdmii_timing.VSyncWidth,
	              (int) pDemo->hdmii_timing.VSyncPolarity,
	              (int) pDemo->hdmii_timing.VBackPorch
	              );
	   xil_printf("\tVideo Dimensions = %d x %d\n\r",
	              (int) pDemo->hdmii_width,
	              (int) pDemo->hdmii_height );

	   if ( (pDemo->hdmii_resolution) == -1 ) {
		   xil_printf( "\tERROR : Invalid resolution, aborting !\n\r" );
		   //return -1;
		   continue;
	   }

	   // No VTC detector at the moment.
#if defined(XPAR_XVTC_NUM_INSTANCES) && defined(XPAR_V_TC_0_DEVICE_ID)
	   //////////////////////////////////////////////////////////////////////
	   // Reset VTC on input data path
	   vdet_init( &(pDemo->vtc_hdmii_detector), pDemo->uDeviceId_VTC_HdmiiDetector );
	   vdet_reset( &(pDemo->vtc_hdmii_detector) );
#endif

	   ///////////////////////////////////////////////////////////////////////////
	   xil_printf( "Video DMA (Input Side) Initialization ...\n\r" );

	   // Stop Input Side of AXI_VDMA (from previous iteration)
	   vfb_rx_stop( &(pDemo->vdma_hdmi) );

	   // Initialize Input Side of AXI VDMA
	   vfb_rx_init_for_demo(
	               &(pDemo->vdma_hdmi),                   // pAxiVdma
	               &(pDemo->vdmacfg_hdmi_write),          // pWriteCfg
	               pDemo->hdmii_resolution,               // uVideoResolution
	               pDemo->hdmio_resolution,               // uStorageResolution
	               (Xuint32) pDemo->buffer[BUFFER_TRANSFERRING],
	               (Xuint32) pDemo->buffer[BUFFER_NEXT_TRANSFER]
	               );

	   //////////////////////////////////////////////////////////////////////
	   xil_printf( "HDMI Output Re-Initialization ...\n\r" );
	   ret = fmc_imageon_hdmio_init( &(pDemo->fmc_imageon),
	                                 1,                      // hdmioEnable = 1
	                                 &(pDemo->hdmio_timing), // pTiming
	                                 0                       // waitHPD = 0
	                                 );
	   if ( !ret ) {
		   xil_printf( "ERROR : Failed to init HDMI Output Interface\n\r" );
		   return XST_FAILURE;
	   }

#if 0 // Activate for debug
	   sleep(1);
	   // Status of AXI VDMA
	   vfb_dump_registers( &(pDemo->vdma_hdmi) );
	   if ( vfb_check_errors( &(pDemo->vdma_hdmi), 1/*clear errors, if any*/ ) ) {
		   vfb_dump_registers( &(pDemo->vdma_hdmi) );
	   }
#endif

	   xil_printf("\n\r");
	   xil_printf( "Done\n\r" );
	   xil_printf("\n\r");

	   sleep(1);
	   break;
	} // end while

	return 0;
}

///////////////////////////////////////////////////////////////////////////
void cleanup_demo()
{
	DisableIntrSystem();
}

///////////////////////////////////////////////////////////////////////////
vbx_timestamp_t frame_buffer_update(demo_t *pDemo, int uses_video_in)
{
	vbx_timestamp_t wait_time;
	//Update buffers; will delay if not ready
	if (uses_video_in) {
		switch_buffers(pDemo);
	}
	wait_time = 0;

	return wait_time;
}

///////////////////////////////////////////////////////////////////////////
