#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "my_funcs.h"

/**
 * rev_string - reverses a string and stores it back
 * @s: input
 */
void rev_string(char *s)
{
	int i, j;
	char tempchar;
	int len = _strlen(s);

	for (i = len - 1, j = 0; i > j; i--, j++)
	{
		tempchar = s[i];
		s[i] = s[j];
		s[j] = tempchar;
	}
}
