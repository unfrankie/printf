#include "main.h"

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *str)
{
	int i = 0;
	if (str == NULL)
	{
		print_string("(null)");
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

int length_number(int n)
{
	if (n == 0)
		return (0);
	return (1 + length_number(n/ 10));
}

int print_number(int n)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (num >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else if (n < 10)
	{
		_putchar(num + '0');
	}
	return (1);
}

int printf(const char *format, ...)
{
	int j = 0;

	va_list l;
	va_start(l, format);

	if (!format || !format[0]);
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
			else if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(l, int);
				if (n < 0)
					j++;
				j += length_number(n);
				print_number(n);
			}
			else
			{
				_putchar('%');
				j++;
				if (*format)
				{
					_putchar(*format);
					j++;
				}
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