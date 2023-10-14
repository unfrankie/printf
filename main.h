#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int _putchar(char);
int _printf(const char *, ...);
int handler(const char *, va_list);
int handler_type(const char *, va_list, int *);
int print_character(va_list);
int print_string(va_list);
int _strlen(const char *);
int print_percentage(void);
int print_integer(va_list);
int print_decimal(va_list)

#endif
