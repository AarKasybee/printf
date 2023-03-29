#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * int_to_oct - converts int to octal
 * @num: input int
 * @s: The buffer to store the octal string
 * Return: octal value as an int
 */
char *int_to_oct(va_list arg_list)
{
	int i = 0, j;
	char *s;
	unsigned int n = va_arg(arg_list, unsigned int);

	s = malloc(12 * sizeof(char));
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (n == 0)
	{
		s[i++] = '0';
	}
	else
	{
		while (n != 0)
		{
			s[i++] = (n % 8) + '0';
			n /= 8;
		}
	}
	s[i] = '\0';
	for (j = 0; j < i / 2; j++)
	{
		char tmp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = tmp;
	}
	return (s);
}
/**
 * print_oct - Prints an integer to stdout
 * @arg_list: List of arguments from va_start
 * Return: The number of characters printed
 */
int print_oct(va_list arg_list)
{
	char *str_ptr = int_to_oct(arg_list);
	int len = 0;
	while (str_ptr && *str_ptr)
	{
		_putchar(*str_ptr++);
		len++;
	}
	free(str_ptr - len);
	return (len);
}
