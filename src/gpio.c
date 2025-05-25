
#include "gpio.h"
#include <Arduino.h>

void gpio_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
}

void gpio_mode_output(uint32_t pin) {
    GPIOB->CRL &= ~(0xF << (pin * 4));
    GPIOB->CRL |= (0x1 << (pin * 4));
}

void gpio_set(uint32_t pin, uint8_t value) {
    if (value)
        GPIOB->BSRR = (1 << pin);
    else
        GPIOB->BRR = (1 << pin);
}
