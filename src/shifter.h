#ifndef ADC_SHIFTER_H_
#define ADC_SHIFTER_H_

#include "leg.h"

typedef struct {
    output_leg_t shift_clock_leg;   // SH_CP - Shift Register Clock;   0->1 - shift data
    output_leg_t serial_data_leg;   // DS    - Serial Data;            0, 1 - data
    output_leg_t storage_clock_leg; // ST_CP - Storage Register Clock; 0->1 - store
    output_leg_t reset_leg;         // MR    - Master Reset;           0 - reset;  1 - do not
    output_leg_t output_enable_leg; // OE    - Output Enable;          0 - enable; 1 - disable
} shifter_t;

void sh_init_shifter(shifter_t* shifter);

#endif // ADC_SHIFTER_H_
