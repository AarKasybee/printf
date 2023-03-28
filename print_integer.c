#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * print_integer - Prints an integer to stdout
 * @arg_list: List of arguments from va_start
 * Return: The number of characters printed
 */
int print_integer(va_list arg_list)
{
	char *str;
	int n, len, m;

	n = va_arg(arg_list, int);
	str = malloc(12 * sizeof(char));
	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	str[_strlen(str)] = '\0';
	int_to_str(n, str);
	len = _strlen(str);
	m = 0;
	while (m < len)
	{
		putchar(str[m]);
		m++;
	}
	free(str);
	return (len);
}

