#include "main.h"

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _printf(const char *format, ...)
{
	va_list l;
	int i = 0;

	if (*format == NULL)
		return (-1);
	
	va_start(l, format)

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		format++;
	}
	return (i);
}
