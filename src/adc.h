#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include <avr/io.h>
#include "inttypes.h"

#define ADC_MAX_VALUE     5
#define ADC_MAX_RAW_VALUE 0b1111111111 // 10bits -> 1023

typedef enum {
    ADC_ANALOGUE_CHANNEL_0 = 0,                                       // 0000
    ADC_ANALOGUE_CHANNEL_1 = (1 << MUX0),                             // 0001
    ADC_ANALOGUE_CHANNEL_2 = (1 << MUX1),                             // 0010
    ADC_ANALOGUE_CHANNEL_3 = (1 << MUX1) | (1 << MUX0),               // 0011
    ADC_ANALOGUE_CHANNEL_4 = (1 << MUX2),                             // 0100
    ADC_ANALOGUE_CHANNEL_5 = (1 << MUX2) | (1 << MUX0),               // 0101
    ADC_ANALOGUE_CHANNEL_6 = (1 << MUX2) | (1 << MUX1),               // 0110
    ADC_ANALOGUE_CHANNEL_7 = (1 << MUX2) | (1 << MUX1) | (1 << MUX0), // 0111
} ADC_ANALOGUE_CHANNEL;

void adc_init(ADC_ANALOGUE_CHANNEL analogue_channel);
uint16_t adc_get_raw_value();
float adc_get_converted_value();

#endif // ADC_ADC_H_
