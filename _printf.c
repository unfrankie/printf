#include "main.h"

/**
  * _printf - produce  output according to a format
  * @format: the format string
  * Return: the number of characters printed
  **/

int _printf(const char *format, ...)
{
	va_list l;
	int i;

	if (format == NULL)
		return (-1);
	size = _strlen(format);
	if (i <= 0)
		return (0);
	va_start(l, format);
	i = handler(format, l);
	_putchar(-1);
	va_end(l);
	return (i);
}

/**
  * handler - type handler
  * @s: string
  * @l: parameter
  * Return: size of parameter
  **/

int handler(const char *s, va_list l)
{
	int i, j, k;

	j = 0;
	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == '%')
		{
			k = handler_type(s, l, &i);
			if (k == -1)
				return (-1);
			j += k;
			continue;
		}
		_putchar(s[i]);
		j = j + 1;
	}
	return (j);
}

/**
  * handler_type - handler typer
  * @s: String
  * @l: parameter
  * @i: iterator
  * Return: size of parameter
  **/

int handler_type(const char *s, va_list l, int *i)
{
	int n, j, percent_type;
	format formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
	};

	*i = *i + 1;

	if (s[*i] == '\0')
		return (-1);
	if (s[*i] == '%')
	{
		_putchar('%');
		return (1);
	}
	percent_type = sizeof(formats) / sizeof(formats[0]);
	for (n = j = 0; j < percent_typer; j++)
	{
		if (s[*i] == formats[j].type)
		{
			n = formats[j].f(l);
			return (n);
		}
	}
	_putchar('%'), _putchar(s[*i]);
	return (2);
}
