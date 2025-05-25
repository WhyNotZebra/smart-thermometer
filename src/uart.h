
#pragma once
#include <stdarg.h>

void uart_init(void);
void uart_send(char c);
void uart_printf(const char* fmt, ...);
