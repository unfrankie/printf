#include "main.h"

/**
  * print_character - print a character
  * @l: parameter
  * Return: 1
  */

int print_character(va_list l)
{
	char c;

	c = va_arg(l, int);
	_putchar(c);
	return (1);
}
