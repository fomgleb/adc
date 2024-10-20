#ifndef ADC_SHIFTER_H_
#define ADC_SHIFTER_H_

#include "pin.h"

typedef struct {
    output_pin_t shift_clock_pin;   // SH_CP - Shift Register Clock;   0->1 - shift data
    output_pin_t serial_data_pin;   // DS    - Serial Data;            0, 1 - data
    output_pin_t storage_clock_pin; // ST_CP - Storage Register Clock; 0->1 - store
    output_pin_t reset_pin;         // MR    - Master Reset;           0 - reset;  1 - do not
    output_pin_t output_enable_pin; // OE    - Output Enable;          0 - enable; 1 - disable
} shifter_t;

void sh_init_shifter(shifter_t* shifter);

#endif // ADC_SHIFTER_H_
