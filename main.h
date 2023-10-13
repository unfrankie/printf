#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_character(va_list l);
int print_string(va_list l);
int _strlen(char *s);
int print_percentage(void);
int print_integer(va_list l);
int print_decimal(va_list l)

#endif
