#ifndef ADC_LEG_H_
#define ADC_LEG_H_

#include <inttypes.h>
#include "boolean.h"

typedef struct {
    const volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t leg_index;
} output_leg_t;

typedef struct {
    const volatile uint8_t* ddr;
    const volatile uint8_t* port;
    const volatile uint8_t* pin;
    const volatile uint8_t leg_index;
} input_leg_t;

output_leg_t leg_create_output_leg(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t leg_index);
input_leg_t leg_create_input_leg(volatile uint8_t* ddr, volatile uint8_t* port, const volatile uint8_t* pin,
                                 volatile uint8_t leg_index);
void leg_set(output_leg_t* leg);
void leg_drop(output_leg_t* leg);
void leg_drop_set(output_leg_t* leg);
void leg_set_drop(output_leg_t* leg);
void leg_drop_set_drop(output_leg_t* leg);
bool leg_get(const input_leg_t* leg);

#endif // ADC_LEG_H_
