#ifndef IGPIO_H_
#define IGPIO_H_

#include <CommonTypes.h>

#define GPIO_LEVEL_LOW      0
#define GPIO_LEVEL_HIGH     1

typedef struct Gpio Gpio_t;

// #pragma weak Gpio_SetPin
void Gpio_SetPin(Gpio_t* const self, uint8_t level);

// #pragma weak Gpio_TogglePin
void Gpio_TogglePin(Gpio_t* const self);

// #pragma weak Gpio_GetPinLevel
uint8_t Gpio_GetPinLevel(Gpio_t* const self);

#endif /* IGPIO_H_ */
