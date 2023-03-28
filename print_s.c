#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * print_s - Prints a string to stdout
 * @s: List of arguments from va_start
 * Return: The number of characters printed
 */
int print_s(va_list s)
{
	char *arg_str = va_arg(s, char *);
	int len_s = 0;

	while (arg_str && *arg_str)
	{
		putchar(*arg_str++);
		len_s++;
	}
	return (len_s);
}
