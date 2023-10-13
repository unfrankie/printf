#include "main.h"

/**
  * print_string - print a string
  * @l: parameter
  * Return: Length of string
  */

int print_string(va_list l)
{
	int i;
	int len;
	char *s;
	
	s = va_arg(l, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
		{
			_putchar(s[i]);
		}
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
		{
			_putchar(s[i]);
		}
		return (len);
	}
}
