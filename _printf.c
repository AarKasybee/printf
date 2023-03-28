#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * _printf - Printf look-alike function
 * @format: input format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int num_char = 0, i = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			num_char += print_c(arg_list);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			num_char += print_s(arg_list);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			num_char += print_integer(arg_list);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			num_char += print_integer(arg_list);
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			num_char++;
			i++;
		}
	}
	va_end(arg_list);
	return (num_char);
}
