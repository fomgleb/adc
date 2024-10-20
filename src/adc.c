#include "adc.h"

#include <avr/io.h>

void
adc_init(ADC_ANALOGUE_CHANNEL adc_channel) {
    ADMUX |= (1 << MUX1) | (1 << MUX2);
    ADCSRA |= (1 << ADEN) | (0x07 << ADPS0);
}

uint16_t
adc_get_raw_value() {
    ADCSRA |= (1 << ADSC);
    while (!((ADCSRA >> ADIF) & 1)) {}
    return ADCL | (ADCH << 8);
}

float
adc_get_converted_value() {
    uint16_t raw_value = adc_get_raw_value();
    return (ADC_MAX_VALUE * raw_value) / (float)ADC_MAX_RAW_VALUE;
}
