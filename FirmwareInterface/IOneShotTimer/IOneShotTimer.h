#ifndef IONESHOTTIMER_H_
#define IONESHOTTIMER_H_

#include <CommonTypes.h>

typedef struct OneShotTimer OneShotTimer_t;

// #pragma weak OneShotTimer_SetCycleTime
void OneShotTimer_SetCycleTime(OneShotTimer_t* const self, uint32_t cycleTime);

// #pragma weak OneShotTimer_Start
void OneShotTimer_Start(OneShotTimer_t* const self);

// #pragma weak OneShotTimer_Stop
void OneShotTimer_Stop(OneShotTimer_t* const self);

#endif /* IONESHOTTIMER_H_ */
