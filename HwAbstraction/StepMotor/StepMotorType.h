#ifndef STEPMOTORTYPE_H_
#define STEPMOTORTYPE_H_

#include "StepMotor.h"
#include <IGpio.h>
#include <IOneShotTimer.h>
#include <ObservableType.h>

struct StepMotor {
	uint32_t steps;
	ufp16x100_t degPerStep;
    Observable_t stepPerformedObservable;
	Gpio_t* enableGpio;
	Gpio_t* stepGpio;
	Gpio_t* dirGpio;
    OneShotTimer_t* squareWaveTimer;
};

struct StepMotorInit {
	ufp16x100_t degPerStep;
	Gpio_t* enableGpio;
    Gpio_t* stepGpio;
    Gpio_t* dirGpio;
    OneShotTimer_t* squareWaveTimer;
};

#endif /* STEPMOTORTYPE_H_ */
