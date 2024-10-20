#include "pin.h"

output_pin_t
pin_create_output_pin(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t pin_index) {
    *ddr |= (1 << pin_index);
    *port &= ~(1 << pin_index);
    output_pin_t new_output_pin = {
        .ddr = ddr,
        .port = port,
        .pin_index = pin_index,
    };
    return new_output_pin;
}

void
pin_set(output_pin_t* pin) {
    *pin->port |= (1 << pin->pin_index);
}

void
pin_drop(output_pin_t* pin) {
    *pin->port &= ~(1 << pin->pin_index);
}

void
pin_drop_set(output_pin_t* pin) {
    pin_drop(pin);
    pin_set(pin);
}

void
pin_set_drop(output_pin_t* pin) {
    pin_set(pin);
    pin_drop(pin);
}

void
pin_drop_set_drop(output_pin_t* pin) {
    pin_drop(pin);
    pin_set(pin);
    pin_drop(pin);
}
