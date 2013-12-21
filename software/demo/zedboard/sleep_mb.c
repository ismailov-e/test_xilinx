#if __MICROBLAZE__

#include "vbx.h"
#include "vbx_port.h"

#include "sleep_mb.h"

int usleep(unsigned int useconds) {
	u32 cycles;

	// convert microseconds to clock cycles
	// freq/1e6 = clock cycles per microsecond
	cycles = (vbx_timestamp_freq()/1000000)*useconds;

	vbx_timestamp_start();
	while (vbx_timestamp() < cycles) {
		asm("nop");
	}
	return 0;
}


int sleep(unsigned int seconds) {

	return usleep(1000000);
}

#endif // __MICROBLAZE__
