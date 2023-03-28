#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * int_to_str - converts integer to string
 * @num: input int
 * @str: output str
 */

void int_to_str(int num, char *str)
{
	int i = 0;
	int sign = 0;
	int j, k;
	char temp;

	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num);
	if (sign)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	/* Reverse the string*/
	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}
