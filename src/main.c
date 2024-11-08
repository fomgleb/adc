#include <avr/io.h>
#include "adc.h"
#include "button.h"
#include "display.h"

static display_t create_display();

int
main() {
    adc_init(ADC_ANALOGUE_CHANNEL_6);

    display_t display = create_display();
    const button_t button = btn_create(&DDRD, &PORTD, &PIND, 2);

    while (true) {
        if (btn_is_pressed(&button)) {
            continue;
        }

        float converted_adc_value = adc_get_converted_value();
        dl_render_positive_float_number(&display, converted_adc_value);
    }
}

static display_t
create_display() {
    display_t display = {
        .shifter =
            {
                .shift_clock_leg = leg_create_output_leg(&DDRB, &PORTB, 0),
                .serial_data_leg = leg_create_output_leg(&DDRB, &PORTB, 1),
                .storage_clock_leg = leg_create_output_leg(&DDRB, &PORTB, 2),
                .reset_leg = leg_create_output_leg(&DDRB, &PORTB, 3),
                .output_enable_leg = leg_create_output_leg(&DDRB, &PORTB, 4),
            },
        .enable_first_digit = leg_create_output_leg(&DDRC, &PORTC, 2),
        .enable_second_digit = leg_create_output_leg(&DDRC, &PORTC, 3),
        .enable_third_digit = leg_create_output_leg(&DDRC, &PORTC, 4),
        .enable_fourth_digit = leg_create_output_leg(&DDRC, &PORTC, 5),
    };
    dl_init_display(&display);
    return display;
}
