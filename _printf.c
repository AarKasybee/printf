#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

int c_id (const char *char_fmt, int loop_i, int counter,  va_list list);
/**
 * _printf - Printf look-alike function
 * @format: input format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int num_char = 0;
	int i = 0;
	int n;
	int len, m;
	va_list arg_list;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		num_char += c_id (format, i, num_char, arg_list);
		if (format[i] == '%' && format[i + 1] == 's')
		{
			fputs(va_arg(arg_list, char *), stdout);
			num_char += strlen(va_arg(arg_list, char *));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			n = va_arg(arg_list, int);
			str = malloc(12 * sizeof(char));
			if (str == NULL)
			{
				exit(0);
			}
			str[strlen(str)] = '\0';
			len = strlen(str);
			m = 0;
			int_to_str(n, str);
			len = strlen(str);
			while (m < len)
			{
				putchar(str[m]);
				m++;
			}
			num_char += len;
			i += 2;
			free(str);
		}
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			n = va_arg(arg_list, int);
			str = malloc(12 * sizeof(char));
			if (str == NULL)
			{
				exit(0);
			}
			str[strlen(str)] = '\0';
			len = strlen(str);
			m = 0;
			int_to_str(n, str);
			len = strlen(str);
			while (m < len)
			{
				putchar(str[m]);
				m++;
			}
			num_char += len;
			i += 2;
			free(str);
		}
		else
		{
			putchar(format[i]);
			num_char++;
			i++;
		}
	}
	va_end(arg_list);
	return (num_char);
}
/**
 * c_id - identifies %c
 * @char_fmt: character specifier
 *
 * Return: returns the number of char
 * */
int c_id (const char *char_fmt, int loop_i, int counter, va_list list)
{
	counter = 0;
	loop_i = 0;
	if (char_fmt[loop_i] == '%' && char_fmt[loop_i + 1] == 'c')
	{
		putchar(va_arg(list, int));
		counter++;
		loop_i += 2;
		return (counter);
	}
	return (counter);
}
