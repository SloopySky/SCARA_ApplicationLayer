#include "StepMotorType.h"
#include <assert.h>

#define DIR_CW	 1
#define DIR_CCW	 0

static inline uint8_t GetDirection(fp32x100_t angularDisplacement);
static inline uint32_t CalculatePulseTime(ufp16x100_t degPerStep, uint16_t rpm);
static inline void StepMotor_SetDirection(const StepMotor_t* const self, uint8_t direction);

void StepMotor_Initialize(StepMotor_t* const self, const StepMotorInit_t* const cfg)
{
	assert(self);
	assert(cfg);
	assert(cfg->enableGpio);
	assert(cfg->stepGpio);
	assert(cfg->dirGpio);
	assert(cfg->squareWaveTimer);
	
	self->steps = 0;
	self->degPerStep = cfg->degPerStep;
	self->enableGpio = cfg->enableGpio;
	self->stepGpio = cfg->stepGpio;
	self->dirGpio = cfg->dirGpio;
	self->squareWaveTimer = cfg->squareWaveTimer;

	Observable_Initialize(&self->stepPerformedObservable);
}

void StepMotor_Move(StepMotor_t* const self, ufp16x100_t rpm, fp32x100_t angularDisplacement)
{
	assert(self);

	uint8_t direction = GetDirection(angularDisplacement);

	if (angularDisplacement < 0) angularDisplacement = -angularDisplacement;
	self->steps = angularDisplacement / self->degPerStep;

	uint32_t cycleTime = CalculatePulseTime(self->degPerStep, rpm);
	OneShotTimer_SetCycleTime(self->squareWaveTimer, cycleTime);

	StepMotor_SetDirection(self, direction);
	Gpio_SetPin(self->stepGpio, GPIO_LEVEL_HIGH);
	OneShotTimer_Start(self->squareWaveTimer);
}

void StepMotor_Stop(StepMotor_t* const self)
{
	assert(self);

	OneShotTimer_Stop(self->squareWaveTimer);
	Gpio_SetPin(self->stepGpio, GPIO_LEVEL_LOW);
	self->steps = 0;
}

void StepMotor_Enable(StepMotor_t* const self)
{
	assert(self);
	assert(self->enableGpio);

	Gpio_SetPin(self->enableGpio, GPIO_LEVEL_LOW);
}

void StepMotor_Disable(StepMotor_t* const self)
{
	assert(self);
	assert(self->enableGpio);

	Gpio_SetPin(self->enableGpio, GPIO_LEVEL_HIGH);
}

void StepMotor_SquareWaveTimerElapsedHandler(StepMotor_t* const self)
{
	assert(self);

	/* Count steps on falling edge */
	if (Gpio_GetPinLevel(self->stepGpio) == 0)
	{
		self->steps--;
		Observable_Notify(&self->stepPerformedObservable, NULL);
	}

	/* Trigger next square wave if there are steps to perform */
	if (self->steps > 0)
	{
		Gpio_TogglePin(self->stepGpio);
		OneShotTimer_Start(self->squareWaveTimer);
	}
}

static inline uint8_t GetDirection(fp32x100_t angularDisplacement)
{
	return angularDisplacement < 0 ? DIR_CCW : DIR_CW;
}

static inline uint32_t CalculatePulseTime(ufp16x100_t degPerStep, uint16_t rpm)
{
	/*
	steps_in_deg = 1 / degPerStep
	deg_in_rev = 360
	us_in_min = 60 (s in min) * 10^6 (us in s)
	
	              deg_in_rev * steps_in_deg 
	1 [rev/min] = ------------------------- [steps/us]
						  us_in_min

									  360						6
	1 [rev/min] = = steps_in_deg * --------- = steps_in_deg * ----- [steps/us]
								   60 * 10^6				  10^6

										  6
	f [steps/us] = rpm * steps_in_deg * ---- 
										10^6

								10^6
	T [us/step] = 1/f = ----------------------
						6 * rpm * steps_in_deg

	50% duty cycle:
									10^6			  250000 * deg_in_step
	Pulse time [us] = T/2 = ----------------------- = --------------------
							12 * rpm * steps_in_deg   		3 * rpm
	*/
	return (250000 * degPerStep) / (3 * rpm);
}

static inline void StepMotor_SetDirection(const StepMotor_t* const self, uint8_t direction)
{
	Gpio_SetPin(self->dirGpio, direction);
}
