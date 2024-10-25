#include "adc.h"

void
adc_init(ADC_ANALOGUE_CHANNEL adc_channel) {
    ADMUX |= adc_channel;
    ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
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
