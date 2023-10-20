#include "main.h"

/**
 * get_sz - a function to cal the size to cast the argument
 * @format: format of string
 * @g: argument
 * Return: should be precision
 */
int get_sz(const char *format, int *g)
{
	int curr_g = *g + 1;
	int sz = 0;

	if (format[curr_g] == 'l')
		sz = S_LONG;
	else if (format[curr_g] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*g = curr_g - 1;
	else
		*g = curr_g;

	return (sz);
}

