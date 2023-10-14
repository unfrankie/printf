#include "main.h"

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _printf(const char *format, ...)
{
	int i;
	va_list l;

	if (format == NULL)
		return (-1);

	size = _strlen(format);
	if (i <= 0)
		return (0);

	va_start(l, format);
	size = handler(format, l);

	_putchar(-1);
	va_end(l);

	return (i);
}
