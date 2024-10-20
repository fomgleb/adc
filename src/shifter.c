#include "shifter.h"

void
sh_init_shifter(shifter_t* shifter) {
    pin_drop(&shifter->shift_clock_pin);
    pin_drop(&shifter->serial_data_pin);
    pin_drop(&shifter->storage_clock_pin);
    pin_set(&shifter->reset_pin);
    pin_drop(&shifter->output_enable_pin);
}
