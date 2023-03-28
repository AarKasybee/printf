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
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			putchar(va_arg(arg_list, int));
			num_char++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *arg_str = va_arg(arg_list, char *);
			fputs(arg_str, stdout);
			num_char += strlen(arg_str);
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
