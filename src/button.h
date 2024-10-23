#ifndef ADC_BUTTON_H_
#define ADC_BUTTON_H_

#include "leg.h"

typedef input_leg_t button_t;

button_t btn_create(volatile uint8_t* ddr, volatile uint8_t* port, const volatile uint8_t* pin,
                    volatile uint8_t leg_index);
bool btn_is_pressed(const button_t* button);

#endif // ADC_BUTTON_H_
