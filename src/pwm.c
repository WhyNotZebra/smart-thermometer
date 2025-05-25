
#include "pwm.h"
#include <Arduino.h>

void pwm_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_TIM1EN;
    GPIOA->CRH &= ~GPIO_CRH_CNF8;
    GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8;
    TIM1->PSC = 720 - 1;
    TIM1->ARR = 100;
    TIM1->CCR1 = 0;
    TIM1->CCMR1 = 0x0060;
    TIM1->CCER = TIM_CCER_CC1E;
    TIM1->BDTR = TIM_BDTR_MOE;
    TIM1->CR1 = TIM_CR1_CEN;
}

void pwm_set_duty(uint8_t duty) {
    TIM1->CCR1 = duty;
}
