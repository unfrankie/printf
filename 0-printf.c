#include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  * Return: 1
  **/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * print_string - print string
  * @s: the string
  * Return: i
  **/

int print_string(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		print_string("(null)");
		return (6);
	}
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _printf(const char *format, ...)
{
	int j = 0;
	va_list l;

	va_start(l, format);
	if (!format || !format[0])
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(l, int);

				j += _putchar(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(l, char *);

				j += print_string(s);
			}
			else if (*format == '%')
			{
				_putchar('%');
				j++;
			}
			format++;
		}
		else
		{
			_putchar(*format);
			format++;
			j++;
		}
	}
	return (j);
}
