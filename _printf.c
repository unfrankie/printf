#include "main.h"

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _printf(const char *format, ...)
{
	int i;
	va_list l_var;

	if (format == NULL)
		return (-1);
	i = _strlen(format);
	if (i <= 0)
		return (0);
	va_start(l_var, format);
	i = type_format(format, l_var);
	_putchar(-1);
	va_end(l_var);
	return (i);
}
