#include <stdio.h>

#include "demo.h"
#include "vbx_test.h"

#define HDMI_CALL_INTERVAL_MS 100
static UINT32 HDMI_MsCount;

///////////////////////////////////////////////////////////////////////////
void switch_buffers(demo_t *pDemo)
{
	pixel *temp;
	int Status;
    pixel **buffer = pDemo->buffer;
    XAxiVdma *pAxiVdma  = &(pDemo->vdma);
    XAxiVdma_DmaSetup *pReadCfg = &(pDemo->vdmacfg_read);

	// Tell frame reader to start using buffer[BUFFER_PROCESSING]
	// (which will be the new buffer[BUFFER_READING])
	pReadCfg->FrameStoreStartAddr[0] = (u32) buffer[BUFFER_PROCESSING];
	Status = XAxiVdma_DmaSetBufferAddr(pAxiVdma,
	                                   XAXIVDMA_READ,
	                                   pReadCfg->FrameStoreStartAddr);
	Status = XAxiVdma_DmaStart(pAxiVdma, XAXIVDMA_READ);

	// move buffer pointers
	temp = buffer[BUFFER_READING];
	buffer[BUFFER_READING]    = buffer[BUFFER_PROCESSING];
	buffer[BUFFER_PROCESSING] = buffer[BUFFER_READY];
	buffer[BUFFER_READY]      = temp;

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
	int i;
	UINT16 TxRev;

    pDemo->vdma_dev_id = XPAR_AXI_VDMA_0_DEVICE_ID;
    pDemo->frame_buffer_base = 0x10000000;

#if __ARM_ARCH_7A__
	vbx_zynq_remap_ddr_uncached();
#if VBX_USE_AXI_INSTR_PORT_NORMAL_MEMORY
	vbx_zynq_set_instr_port_normal_uncached();
#elif VBX_USE_AXI_INSTR_PORT_DEVICE_MEMORY
	vbx_zynq_set_instr_port_device_memory();
#endif
#endif // __ARM_ARCH_7A__

#if XPAR_XTMRCTR_NUM_INSTANCES && !(__ARM_ARCH_7A__ && VBX_USE_A9_PMU_TIMER)
	timestamp_timer_init(&(pDemo->timestamp_timer));
#else
	timestamp_timer_init();
#endif
	slide_switches_init(&(pDemo->slide_switches));
	buttons_init(&(pDemo->buttons));
	mxp_init(&(pDemo->vbx_mxp));

	///////////////////////////////////////////////////////////////////////////
	// Only actually need the first three buffers, but allocating all.
    pDemo->buffer = (pixel **)malloc(sizeof(pixel*)*VIDEO_BUFFERS);
	///////////////////////////////////////////////////////////////////////////
	for (i = 0; i < VIDEO_BUFFERS; i++) {
		pDemo->buffer[i] = (pixel *) (pDemo->frame_buffer_base + \
		                              i*IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel));
	}
	for (i = 0; i < VIDEO_BUFFERS; i++) {
		xil_printf("frame_buffer[%d] = 0x%08x\n\r", i, (unsigned int) pDemo->buffer[i]);
	}

    pDemo->short_buffer = (unsigned short *) (pDemo->buffer[VIDEO_BUFFERS-1] +
                                              IMAGE_WIDTH*IMAGE_HEIGHT);

    ///////////////////////////////////////////////////////////////////////////

    // Initialization code from
    // https://github.com/analogdevicesinc/no-OS/tree/master/ADV7511_ZedBoard/main.c

    // Perform any required platform init
    // including hardware reset to HDMI devices
#if __ARM_ARCH_7A__
	HAL_PlatformInit(XPAR_AXI_IIC_0_BASEADDR,
					 XPAR_SCUTIMER_DEVICE_ID,
					 XPAR_SCUGIC_SINGLE_DEVICE_ID,
					 XPAR_SCUTIMER_INTR);
#elif __MICROBLAZE__
	HAL_PlatformInit_MB(XPAR_AXI_IIC_0_BASEADDR,
	                    XPAR_AXI_TIMER_1_DEVICE_ID,
	                    XPAR_AXI_TIMER_1_CLOCK_FREQ_HZ);
#endif

	Xil_ExceptionEnable();

	Video_Init(RESOLUTION_1920x1080,
	           pDemo->vdma_dev_id,
	           &(pDemo->vdma),
	           &(pDemo->vdmacfg_read),
	           (u32) (pDemo->buffer[BUFFER_READING]));

#if 1
	ADIAPI_TxGetChipRevision(&TxRev);
	xil_printf("  HDMI-TX:  ADV7511 Rev 0x%x\r\n", TxRev);

	/* Initialize ADI repeater software and h/w */
	ADIAPI_TransmitterInit();
	ADIAPI_TransmitterSetPowerMode(REP_POWER_UP);

	HDMI_MsCount = HAL_GetCurrentMsCount();
#endif

	return 0;
}

///////////////////////////////////////////////////////////////////////////
void cleanup_demo()
{

}

///////////////////////////////////////////////////////////////////////////
vbx_timestamp_t frame_buffer_update(demo_t *pDemo, int uses_video_in)
{
	vbx_timestamp_t wait_time;
	u32 elapsed;

	//Update buffers; will delay if not ready
	if (uses_video_in) {
		switch_buffers(pDemo);
	}

#if 1
	elapsed = ATV_GetElapsedMs(HDMI_MsCount, NULL);
	// printf("elapsed = %lu\r\n", elapsed);
	// printf("cur = %lu\r\n", HAL_GetCurrentMsCount());
	if (elapsed >= HDMI_CALL_INTERVAL_MS) {
		HDMI_MsCount = HAL_GetCurrentMsCount();
		ADIAPI_TransmitterMain();
	}
#endif

	wait_time = 0;

	return wait_time;
}

///////////////////////////////////////////////////////////////////////////
