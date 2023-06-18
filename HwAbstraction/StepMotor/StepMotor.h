#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_

#include <CommonTypes.h>

typedef struct StepMotor StepMotor_t;
typedef struct StepMotorInit StepMotorInit_t;

void StepMotor_Initialize(StepMotor_t* const self, const StepMotorInit_t* const cfg);
void StepMotor_Move(StepMotor_t* const self, ufp16x100_t rpm, fp32x100_t angularDisplacement);
void StepMotor_Stop(StepMotor_t* const self);
void StepMotor_Enable(StepMotor_t* const self);
void StepMotor_Disable(StepMotor_t* const self);
void StepMotor_SquareWaveTimerElapsedHandler(StepMotor_t* const self);

#endif /* STEPMOTOR_H_ */
