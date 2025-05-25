
#include "delay.h"
#include <Arduino.h>

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 8000; i++) {
        __asm("nop");
    }
}

void delay_us(uint32_t us) {
    for (uint32_t i = 0; i < us * 8; i++) {
        __asm("nop");
    }
}
