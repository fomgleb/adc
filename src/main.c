#include <avr/io.h>
#include "adc.h"
#include "display.h"

static display_t create_display();

int
main() {
    adc_init(ADC_ANALOGUE_CHANNEL_6);

    display_t display = create_display();

    while (true) {
        float converted_adc_value = adc_get_converted_value();
        dl_render_positive_float_number(&display, converted_adc_value);
    }
}

static display_t
create_display() {
    display_t display = {
        .shifter =
            {
                .shift_clock_pin = pin_create_output_pin(&DDRB, &PORTB, 0),
                .serial_data_pin = pin_create_output_pin(&DDRB, &PORTB, 1),
                .storage_clock_pin = pin_create_output_pin(&DDRB, &PORTB, 2),
                .reset_pin = pin_create_output_pin(&DDRB, &PORTB, 3),
                .output_enable_pin = pin_create_output_pin(&DDRB, &PORTB, 4),
            },
        .enable_first_digit = pin_create_output_pin(&DDRC, &PORTC, 2),
        .enable_second_digit = pin_create_output_pin(&DDRC, &PORTC, 3),
        .enable_third_digit = pin_create_output_pin(&DDRC, &PORTC, 4),
        .enable_fourth_digit = pin_create_output_pin(&DDRC, &PORTC, 5),
    };
    dl_init_display(&display);
    return display;
}
