#ifndef ADC_DISPLAY_H_
#define ADC_DISPLAY_H_

#include "boolean.h"
#include "shifter.h"

#define NUMBER_OF_DIGITS 4

typedef struct {
    shifter_t shifter;
    output_pin_t enable_first_digit;
    output_pin_t enable_second_digit;
    output_pin_t enable_third_digit;
    output_pin_t enable_fourth_digit;
} display_t;

typedef enum {
    DL_DIGIT_INDEX_1 = 1,
    DL_DIGIT_INDEX_2,
    DL_DIGIT_INDEX_3,
    DL_DIGIT_INDEX_4,
} DL_DIGIT_INDEX;

typedef enum {
    DL_DIGIT_VALUE_0 = 0,
    DL_DIGIT_VALUE_1,
    DL_DIGIT_VALUE_2,
    DL_DIGIT_VALUE_3,
    DL_DIGIT_VALUE_4,
    DL_DIGIT_VALUE_5,
    DL_DIGIT_VALUE_6,
    DL_DIGIT_VALUE_7,
    DL_DIGIT_VALUE_8,
    DL_DIGIT_VALUE_9,
} DL_DIGIT_VALUE;

void dl_init_display(display_t* display);
void dl_render_digit(display_t* display, DL_DIGIT_VALUE digit_value, DL_DIGIT_INDEX digit_index, bool place_dot);
void dl_render_positive_float_number(display_t* display, float number);

#endif // ADC_DISPLAY_H_
