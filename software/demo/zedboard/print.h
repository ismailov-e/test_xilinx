#ifndef __PRINT_H
#define __PRINT_H

#if __MICROBLAZE__
#include "ps7_uart.h"
#define PRINT ps7_uart_print
#else
#define PRINT printf
#endif

#define MAX_PRINT_LEN 100

#endif // __PRINT_H
