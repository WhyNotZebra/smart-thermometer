
#pragma once
#include <stdint.h>

#define LCD_RS PB0
#define LCD_E  PB1
#define LCD_D4 PB2
#define LCD_D5 PB3
#define LCD_D6 PB4
#define LCD_D7 PB5

void lcd_init(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_write_char(char c);
void lcd_printf(const char* fmt, ...);
