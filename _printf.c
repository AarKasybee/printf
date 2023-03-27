#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * _printf - Printf look-alike function
 * @format: input format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int num_char = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(arg_list, int));
					num_char++;
					break;
				case 's':
					num_char += fputs(va_arg(arg_list, char *), stdout);
					break;
				default:
					putchar(*format);
					num_char++;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(arg_list);
	return (num_char);
}
