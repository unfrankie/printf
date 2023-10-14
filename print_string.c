#include "main.h"

/**
  * print_string - print a string
  * @l: parameter
  * Return: Length of string
  */

int print_string(va_list l)
{
	char *s;
	int len;

	s = va_arg(l, char*);
	len = print((s != NULL) ? s : "(null)");

	return (len);
}
