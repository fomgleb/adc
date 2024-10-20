#ifndef ADC_PIN_H_
#define ADC_PIN_H_

#include <inttypes.h>

typedef struct {
    const volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t pin_index;
} output_pin_t;

output_pin_t pin_create_output_pin(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t pin_index);
void pin_set(output_pin_t* pin);
void pin_drop(output_pin_t* pin);
void pin_drop_set(output_pin_t* pin);
void pin_set_drop(output_pin_t* pin);
void pin_drop_set_drop(output_pin_t* pin);

#endif // ADC_PIN_H_
