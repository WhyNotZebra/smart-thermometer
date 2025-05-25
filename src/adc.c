
#include "adc.h"
#include <Arduino.h>

void adc_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    ADC1->SQR3 = 0;
    ADC1->CR2 |= ADC_CR2_ADON;
}

uint16_t adc_read(void) {
    ADC1->CR2 |= ADC_CR2_ADON;
    while (!(ADC1->SR & ADC_SR_EOC));
    return ADC1->DR;
}
