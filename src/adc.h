#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "inttypes.h"

#define ADC_MAX_VALUE     5
#define ADC_MAX_RAW_VALUE 0b1111111111 // 10bits -> 1023

typedef enum {
    ADC_ANALOGUE_CHANNEL_0 = 0b000,
    ADC_ANALOGUE_CHANNEL_1 = 0b001,
    ADC_ANALOGUE_CHANNEL_2 = 0b010,
    ADC_ANALOGUE_CHANNEL_3 = 0b011,
    ADC_ANALOGUE_CHANNEL_4 = 0b100,
    ADC_ANALOGUE_CHANNEL_5 = 0b101,
    ADC_ANALOGUE_CHANNEL_6 = 0b110,
    ADC_ANALOGUE_CHANNEL_7 = 0b111,
} ADC_ANALOGUE_CHANNEL;

void adc_init(ADC_ANALOGUE_CHANNEL analogue_channel);
uint16_t adc_get_raw_value();
float adc_get_converted_value();

#endif // ADC_ADC_H_
