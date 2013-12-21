#if __MICROBLAZE__
#include "xil_io.h"
#include "ps7_uart.h"

#define PS7_UART_BASEADDR 0xE0001000

/* Write to memory location or register */
#define X_mWriteReg(BASE_ADDRESS, RegOffset, data) \
	*(unsigned int *)(BASE_ADDRESS + RegOffset) = ((unsigned int) data);
/* Read from memory location or register */
#define X_mReadReg(BASE_ADDRESS, RegOffset) \
	*(unsigned int *)(BASE_ADDRESS + RegOffset);

#define XUartChanged_IsTransmitFull(BaseAddress) \
	((Xil_In32((BaseAddress) + 0x2C) & 0x10) == 0x10)

///////////////////////////////////////////////////////////////////////////
void XUartChanged_SendByte(u32 BaseAddress, u8 Data)
{
	// Wait until there is space in TX FIFO
	while (XUartChanged_IsTransmitFull(BaseAddress));

	// Write the byte into the TX FIFO
	X_mWriteReg(BaseAddress, 0x30, Data);
}

///////////////////////////////////////////////////////////////////////////
void outbyte(char c) {
	 XUartChanged_SendByte(PS7_UART_BASEADDR, c);
}

///////////////////////////////////////////////////////////////////////////
void ps7_uart_print(char *ptr)
{
	while (*ptr) {
		outbyte (*ptr++);
	}
}

///////////////////////////////////////////////////////////////////////////
#endif // __MICROBLAZE__
