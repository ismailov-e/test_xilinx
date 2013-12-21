#ifndef __DEMO_CONTEXT_H
#define __DEMO_CONTEXT_H

#include "xparameters.h"
#if __MICROBLAZE__
#include "sleep_mb.h"
#else
#include "sleep.h"
#endif

#include "print.h"

#include "fmc_iic.h"
#include "fmc_imageon.h"

#ifdef XPAR_XVTC_NUM_INSTANCES
#include "xvtc.h"
#endif

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
#define WRITE_INTR_ID		XPAR_INTC_0_AXIVDMA_0_VEC_ID
#else
#define INTC_DEVICE_ID		XPAR_SCUGIC_0_DEVICE_ID
#define WRITE_INTR_ID		XPAR_FABRIC_AXIVDMA_0_VEC_ID
#endif

#if defined(XPAR_VECTORBLOX_MXP_NUM_INSTANCES) || defined(XPAR_VECTORBLOX_MXP_ARM_NUM_INSTANCES)
#include "vectorblox_mxp.h"
#endif

#include "pixel.h"

#include "video_resolution.h"
#include "video_detector.h"
#include "video_generator.h"
#include "video_frame_buffer.h"
#include "vfb_for_demo.h"

// This structure contains the context
//  for the FMC-IMAGEON HDMI Video Frame Buffer design
typedef struct demo_t
{
	// IP base addresses
	Xuint32 uBaseAddr_IIC_FmcImageon;
	Xuint32 uDeviceId_VTC_HdmiiDetector;
	Xuint32 uDeviceId_VTC_HdmioGenerator;
	Xuint32 uDeviceId_VDMA_HdmiFrameBuffer;
	Xuint32 uBaseAddr_MEM_HdmiFrameBuffer;  // address of FB in memory
	Xuint32 uNumFrames_HdmiFrameBuffer;

	fmc_iic_t fmc_imageon_iic;

	fmc_imageon_t fmc_imageon;

#if defined(XPAR_XVTC_NUM_INSTANCES)
#if defined(XPAR_V_TC_0_DEVICE_ID)
	XVtc vtc_hdmii_detector;
#endif
#if defined(XPAR_V_TC_1_DEVICE_ID)
	XVtc vtc_hdmio_generator;
#endif
#endif

	XAxiVdma vdma_hdmi;
	XAxiVdma_DmaSetup vdmacfg_hdmi_read;
	XAxiVdma_DmaSetup vdmacfg_hdmi_write;

	Xuint32 bVerbose;

	// HDMI Output settings
	Xuint32 hdmio_width;
	Xuint32 hdmio_height;
	Xuint32 hdmio_resolution;
	fmc_imageon_video_timing_t hdmio_timing;

	// HDMI Input Settings
	Xuint32 hdmii_locked;
	Xuint32 hdmii_width;
	Xuint32 hdmii_height;
	Xuint32 hdmii_resolution;
	fmc_imageon_video_timing_t hdmii_timing;

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
