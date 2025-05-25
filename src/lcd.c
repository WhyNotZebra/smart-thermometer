
#include "lcd.h"
#include "gpio.h"
#include "delay.h"

void lcd_pulse_enable(void) {
    gpio_set(LCD_E, 1);
    delay_us(1);
    gpio_set(LCD_E, 0);
    delay_us(100);
}

void lcd_send_nibble(uint8_t nibble) {
    gpio_set(LCD_D4, (nibble >> 0) & 1);
    gpio_set(LCD_D5, (nibble >> 1) & 1);
    gpio_set(LCD_D6, (nibble >> 2) & 1);
    gpio_set(LCD_D7, (nibble >> 3) & 1);
    lcd_pulse_enable();
}

void lcd_send_byte(uint8_t byte, uint8_t rs) {
    gpio_set(LCD_RS, rs);
    lcd_send_nibble(byte >> 4);
    lcd_send_nibble(byte & 0x0F);
}

void lcd_init(void) {
    gpio_mode_output(LCD_RS);
    gpio_mode_output(LCD_E);
    gpio_mode_output(LCD_D4);
    gpio_mode_output(LCD_D5);
    gpio_mode_output(LCD_D6);
    gpio_mode_output(LCD_D7);
    delay_ms(20);
    lcd_send_nibble(0x03);
    delay_ms(5);
    lcd_send_nibble(0x03);
    delay_us(100);
    lcd_send_nibble(0x03);
    lcd_send_nibble(0x02);
    lcd_send_byte(0x28, 0);
    lcd_send_byte(0x0C, 0);
    lcd_send_byte(0x06, 0);
    lcd_send_byte(0x01, 0);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x00 : 0x40;
    lcd_send_byte(0x80 | (addr + col), 0);
}

void lcd_write_char(char c) {
    lcd_send_byte(c, 1);
}

void lcd_printf(const char* fmt, ...) {
    char buf[32];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    for (int i = 0; buf[i]; i++) {
        lcd_write_char(buf[i]);
    }
}
