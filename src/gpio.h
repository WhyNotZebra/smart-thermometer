
#pragma once
#include <stdint.h>

void gpio_init(void);
void gpio_mode_output(uint32_t pin);
void gpio_set(uint32_t pin, uint8_t value);
