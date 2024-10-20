#include "display.h"

#include <util/delay.h>

void
dl_init_display(display_t* display) {
    sh_init_shifter(&display->shifter);
    pin_drop(&display->enable_first_digit);
    pin_drop(&display->enable_second_digit);
    pin_drop(&display->enable_third_digit);
    pin_drop(&display->enable_fourth_digit);
}

static void
render_digit(display_t* display, DL_DIGIT_VALUE digit_value, bool place_dot) {
    switch (digit_value) {
        case DL_DIGIT_VALUE_0: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_set(&display->shifter.serial_data_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_1: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_set(&display->shifter.serial_data_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_2: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_3: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_4: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_5: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_6: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_7: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_set(&display->shifter.serial_data_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_8: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        case DL_DIGIT_VALUE_9: {
            if (place_dot) {
                pin_drop(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
            } else {
                pin_set(&display->shifter.serial_data_pin);
                pin_set_drop(&display->shifter.shift_clock_pin);
                pin_drop(&display->shifter.serial_data_pin);
            }
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_drop(&display->shifter.serial_data_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            pin_set_drop(&display->shifter.shift_clock_pin);
            break;
        }
        default: break;
    }
}

static output_pin_t*
get_pin_by_digit_index(display_t* display, DL_DIGIT_INDEX digit) {
    switch (digit) {
        case DL_DIGIT_INDEX_1: return &display->enable_first_digit; break;
        case DL_DIGIT_INDEX_2: return &display->enable_second_digit; break;
        case DL_DIGIT_INDEX_3: return &display->enable_third_digit; break;
        case DL_DIGIT_INDEX_4: return &display->enable_fourth_digit; break;
        default: break;
    }
}

void
dl_render_digit(display_t* display, DL_DIGIT_VALUE digit_value, DL_DIGIT_INDEX digit_index, bool place_dot) {
    output_pin_t* digit_index_pin = get_pin_by_digit_index(display, digit_index);
    render_digit(display, digit_value, place_dot);
    pin_set_drop(&display->shifter.storage_clock_pin);
    pin_set(digit_index_pin);
    _delay_ms(1);
    pin_drop(digit_index_pin);
}

void
dl_render_positive_float_number(display_t* display, float float_number) {
    float_number = (float_number < 0) ? -float_number : float_number;

    if (float_number >= 10000) {
        for (DL_DIGIT_INDEX i = DL_DIGIT_INDEX_1; i <= DL_DIGIT_INDEX_4; ++i) {
            dl_render_digit(display, DL_DIGIT_VALUE_9, i, false);
        }
        return;
    }

    uint32_t integer_number;
    DL_DIGIT_INDEX dot_index;
    if (float_number >= 1000) {
        integer_number = (float_number * 10 + 0.5f) / 10;
        dot_index = DL_DIGIT_INDEX_4;
    } else if (float_number >= 100) {
        integer_number = (float_number * 100 + 0.5f) / 10;
        dot_index = DL_DIGIT_INDEX_3;
    } else if (float_number >= 10) {
        integer_number = (float_number * 1000 + 0.5f) / 10;
        dot_index = DL_DIGIT_INDEX_2;
    } else {
        integer_number = (float_number * 10000 + 0.5f) / 10;
        dot_index = DL_DIGIT_INDEX_1;
    }

    uint8_t digits[NUMBER_OF_DIGITS] = {integer_number / 1000, (integer_number % 1000) / 100,
                                        (integer_number % 100) / 10, integer_number % 10};

    while (digits[0] == 0 && dot_index != DL_DIGIT_INDEX_1 && (digits[1] != 0 || digits[2] != 0 || digits[3] != 0)) {
        for (uint8_t i = 1; i < NUMBER_OF_DIGITS; ++i) {
            digits[i - 1] = digits[i];
        }
        digits[NUMBER_OF_DIGITS - 1] = 0;
    }

    for (uint8_t i = 0; i < NUMBER_OF_DIGITS; ++i) {
        dl_render_digit(display, digits[i], (DL_DIGIT_INDEX)(i + 1), (dot_index == (DL_DIGIT_INDEX)(i + 1)));
    }
}
