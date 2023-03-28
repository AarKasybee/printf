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
	int num_bits = 0;
	unsigned int mask = ~0;
	int i;
	char *binary = malloc(8 * sizeof(char));

	while (mask != 0)
	{
		if ((num & mask) == 0)
		{
			break;
		}
		num_bits++;
		mask <<= 1;
	}
	binary = realloc(binary, num_bits + 1);
	for (i = num_bits - 1; i >= 0; i--)
	{
		binary[i] = (num & 1) + '0';
		num >>= 1;
	}
	binary[num_bits] = '\0';
	return (binary);
}
