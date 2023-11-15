#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/*printf main program*/
int _printf(const char *format, ...);

/*type format */
int print_string(va_list l_s);
int print_charcter(va_list l_c);
int print_number(va_list l_n);

/*printf handler*/
int type_format(const char *s, va_list l_v);
int type_handler(const char *type, va_list l_v, int *i);

/*utils_0.c*/
int _strlen(const char *str);
int display(char *s);
char *itoa(long int n, int base);
int _putchar(char c);
int mem_char(char c);

/**
  * struct type_f - Type format struct
  * @t: Format
  * @func: function associated
  **/

typedef struct type_f
{
	char t;
	int (*func)(va_list);
} format;

#endif
