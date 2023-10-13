#include "main.h"

/**
  * print_integer - print integer
  * @l: parameter
  * Return: integer
  */
int print_integer(va_list l)
{
	int n = va_arg(l, int);
	int number;

	last_number = number % 10;
	int m;
	int i = 1;
	int j = 1;

	n = n / 10;
	number = n;

	if (last_number < 0)
	{
		_putchar('-');
		number = -number;
		n = -n;
		last_number = -last_number;
		i++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			j = j * 10;
			number = number / 10;
		}
		number = n;
		while (j > 0)
		{
			m = number / j;
			_putcher(m + '0');
			number = number - (m * j);
			j = j / 10;
			i++;
		}
	}
	_putchar(last_number + '0');
	return (i);
}
