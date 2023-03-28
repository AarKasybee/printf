#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * bin_printer - Prints a string or a binary representation
 * of an unsigned int to stdout
 * @s: List of arguments from va_start
 * Return: The number of characters printed
 */
int bin_printer(va_list s)
{
	char *arg_str = va_arg(s, char *);
	unsigned int arg_uint = va_arg(s, unsigned int);
	int len_s;

	if (strcmp(arg_str, "%b") == 0)
	{
		char *binary = to_bin(arg_uint);

		fputs(binary, stdout);
		len_s = _strlen(binary);
		free(binary);
	}
	else
	{
		fputs(arg_str, stdout);
		len_s = _strlen(arg_str);
	}
	return (len_s);
}
