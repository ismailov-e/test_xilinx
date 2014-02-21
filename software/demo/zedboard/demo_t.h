#ifndef __DEMO_CONTEXT_H
#define __DEMO_CONTEXT_H

#include "xparameters.h"

#include "xaxivdma.h"
#include "xil_exception.h"
#include "xil_io.h"
#include "xgpio.h"
#ifdef XPAR_XTMRCTR_NUM_INSTANCES
#include "xtmrctr.h"
#endif

#ifdef XPAR_INTC_0_DEVICE_ID
#include "xintc.h"
#else
#include "xscugic.h"
#endif

#ifdef XPAR_INTC_0_DEVICE_ID
#define INTC_DEVICE_ID		XPAR_INTC_0_DEVICE_ID
#else
#define INTC_DEVICE_ID		XPAR_SCUGIC_0_DEVICE_ID
#endif

#if defined(XPAR_VECTORBLOX_MXP_NUM_INSTANCES) || defined(XPAR_VECTORBLOX_MXP_ARM_NUM_INSTANCES)
#include "vectorblox_mxp.h"
#endif

#include "pixel.h"

#include "cf_hdmi.h"
#include "atv_platform.h"
#include "transmitter.h"
#if __MICROBLAZE__
#include "atv_platform_mb.h"
#endif

typedef struct demo_t
{
	u16 vdma_dev_id;
	u32 frame_buffer_base;

	XAxiVdma vdma;
	XAxiVdma_DmaSetup vdmacfg_read;

	XGpio slide_switches;
	XGpio buttons;
	XGpio leds;

#ifdef XPAR_XTMRCTR_NUM_INSTANCES
	XTmrCtr timestamp_timer;
#endif

#if defined(XPAR_VECTORBLOX_MXP_NUM_INSTANCES) || defined(XPAR_VECTORBLOX_MXP_ARM_NUM_INSTANCES)
	vbx_mxp_t vbx_mxp;
#endif
	int frame_ready;
	struct pixel** buffer;
	unsigned short *short_buffer;
} demo_t;

#endif //__DEMO_CONTEXT_H
