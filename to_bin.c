#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * to_bin - convernts positive values to base 2
 * @num: input int
 *
 * Return: character string of bin numbers
 */
char *to_bin(unsigned int num)
{
	int len = sizeof(unsigned int) * 8;
	char *binary = malloc(len + 1);
	int i;

	for (i = len - 1; i >= 0; i--)
	{
		binary[i] = (num & 1) + '0';
		num >>= 1;
	}
	binary[len] = '\0';
	return binary;
}
