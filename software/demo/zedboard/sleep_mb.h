#ifndef __SLEEP_MB_H
#define __SLEEP_MB_H

#ifdef __cplusplus
extern "C" {
#endif

int usleep(unsigned int useconds);
int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif // __SLEEP_MB_H
