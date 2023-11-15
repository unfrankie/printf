#include "main.h"

/**
  * print_charcter - print charcter
  * @l_c: list character
  * Return: 1
  */

int print_charcter(va_list l_c)
{
	int c;

	c = va_arg(l_c, int);
	_putchar(c);
	return (1);
}

/**
  * print_string - print string
  * @l_s: list string
  * Return: length of string
  */

int print_string(va_list l_s)
{
	char *s;
	int length;

	s = va_arg(l_s, char*);
	length = display((s != NULL) ? s : "(null)");
	return (length);
}

/**
  * print_number - print a number
  * @l_n: list number
  * Return: length of number
  **/

int print_number(va_list l_n)
{
	char *dec;
	int length;

	dec = itoa(va_arg(l_n, int), 10);
	length = display((dec != NULL) ? dec : "NULL");
	return (length);
}

/**
  * type_format - checks for type format
  * @s: pointer to the format string
  * @l_v: list of variables
  * Return: type format
  */

int type_format(const char *s, va_list l_v)
{
	int i, var, type = 0;

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == '%')
		{
			var = type_handler(s, l_v, &i);
			if (var == -1)
				return (-1);

			type += var;
			continue;
		}
		_putchar(s[i]);
		type++;
	}
	return (type);
}

/**
  * type_handler - handls the type format
  * @type: string of type
  * @l_v: list of variables
  * @i: iterator
  * Return: -1 || 1 || size || 2
  **/

int type_handler(const char *type, va_list l_v, int *i)
{
	int size, j, array;
	format type_array[] = {
			{'s', print_string}, {'c', print_charcter},
			{'d', print_number}, {'i', print_number},
	};
	*i = *i + 1;

	if (type[*i] == '\0')
		return (-1);

	if (type[*i] == '%')
	{
		_putchar('%');
		return (1);
	}
	array = sizeof(type_array) / sizeof(type_array[0]);
	for (size = j = 0; j < array; j++)
	{
		if (type[*i] == type_array[j].t)
		{
			size = type_array[j].func(l_v);
			return (size);
		}
	}
	_putchar('%');
	_putchar(type[*i]);
	return (2);
}
