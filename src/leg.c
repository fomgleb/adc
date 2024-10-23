#include "leg.h"

output_leg_t
leg_create_output_leg(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t leg_index) {
    *ddr |= (1 << leg_index);
    *port &= ~(1 << leg_index);
    output_leg_t new_output_leg = {
        .ddr = ddr,
        .port = port,
        .leg_index = leg_index,
    };
    return new_output_leg;
}

void
leg_set(output_leg_t* leg) {
    *leg->port |= (1 << leg->leg_index);
}

void
leg_drop(output_leg_t* leg) {
    *leg->port &= ~(1 << leg->leg_index);
}

void
leg_drop_set(output_leg_t* leg) {
    leg_drop(leg);
    leg_set(leg);
}

void
leg_set_drop(output_leg_t* leg) {
    leg_set(leg);
    leg_drop(leg);
}

void
leg_drop_set_drop(output_leg_t* leg) {
    leg_drop(leg);
    leg_set(leg);
    leg_drop(leg);
}