#include "shifter.h"

void
sh_init_shifter(shifter_t* shifter) {
    leg_drop(&shifter->shift_clock_leg);
    leg_drop(&shifter->serial_data_leg);
    leg_drop(&shifter->storage_clock_leg);
    leg_set(&shifter->reset_leg);
    leg_drop(&shifter->output_enable_leg);
}
