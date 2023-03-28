#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * print_c - Prints a single character to stdout
 * @a: List of arguments from va_start
 * Return: The number of characters printed
 */
int print_c(va_list a)
{
	putchar(va_arg(a, int));
	return (1);
}
