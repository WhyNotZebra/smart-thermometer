
#include "lcd.h"
#include "uart.h"
#include "adc.h"
#include "pwm.h"
#include "gpio.h"
#include "delay.h"

int main(void) {
    gpio_init();
    lcd_init();
    uart_init();
    adc_init();
    pwm_init();

    while (1) {
        uint16_t value = adc_read();
        float temp = value * 5.0 / 1023 * 100;
        lcd_set_cursor(0, 0);
        lcd_printf("Temp: %.2f C", temp);
        uart_printf("Temp: %.2f C", temp);
        if (temp > 30.0) {
            pwm_set_duty(80);
        } else {
            pwm_set_duty(0);
        }
        delay_ms(1000);
    }
}
