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
int bin_printer(char *s)
{
	int len_s = 0;
	int count = 0;
	int zflag = 0;

	while (s && *s)
	{
		if (zflag == 0 && *s != '1')
		{
			count++;
		}
		else
		{
			zflag = 1;
		}
		_putchar(*s++);
		len_s++;
	}
	if (count == len_s)
	{
		_putchar('0');
		len_s++;
	}
	return (len_s);
}
