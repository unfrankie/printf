#include "main.h"

/**
  * _strlen - Calculate the length of a string
  * @str: a pointer to the string
  * Return: the lenght
  */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}

/**
  * display - print string
  * @s: string
  * Return: string length
  */

int display(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		_putchar(s[i]);
	return (i);
}

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  * Return: 1 On success or -1 on error
  */

int _putchar(char c)
{
	return (mem_char(c));
}

/**
  * mem_char - Save the character in a memory
  * @c: Character
  * Return: 1
  **/

int mem_char(char c)
{
	static char mem[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write(1, mem, i);
		i = 0;
	}
	if (c != -1)
		mem[i++] = c;
	return (1);
}

/**
  * itoa - integer to ascii
  * @n: the number to convert
  * @base: the number base
  * Return: pointer
  */

char *itoa(long int n, int base)
{
	static char *arr = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long i;

	i = n;
	if (n < 0)
	{
		i = -n;
		sign = '-';
	}
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = arr[i % base];
		i /= base;
	} while (i != 0);
	if (sign)
		*--p = sign;
	return (p);
}
