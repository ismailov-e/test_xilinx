#ifndef __VFB_FOR_DEMO_H__
#define __VFB_FOR_DEMO_H__

#include "xaxivdma.h"

int vfb_rx_init_for_demo( XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pWriteCfg,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 fb0,
                          Xuint32 fb1 );
int vfb_rx_setup_for_demo( XAxiVdma *pAxiVdma,
                           XAxiVdma_DmaSetup *pWriteCfg,
                           Xuint32 uVideoResolution,
                           Xuint32 uStorageResolution,
                           Xuint32 fb0,
                           Xuint32 fb1);
int vfb_tx_init_for_demo( XAxiVdma *pAxiVdma,
                          XAxiVdma_DmaSetup *pReadCfg ,
                          Xuint32 uVideoResolution,
                          Xuint32 uStorageResolution,
                          Xuint32 uMemAddr,
                          Xuint32 uNumFrames );
int vfb_tx_setup_for_demo( XAxiVdma *pAxiVdma,
                           XAxiVdma_DmaSetup *pReadCfg ,
                           Xuint32 uVideoResolution,
                           Xuint32 uStorageResolution,
                           Xuint32 uMemAddr,
                           Xuint32 uNumFrames );

#endif // __VFB_FOR_DEMO_H__

