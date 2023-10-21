#include "main.h"

/**
 * get_wd - function that get the width printing
 * @format: format for argument
 * @g: arguments
 * @lt: the listed argument
 * Return: should be the width
 */
int get_wd(const char *format, int *g, va_list lt)
{
	int curr_g;
	int wd = 0;

	for (curr_g = *g + 1; format[curr_g] != '\0'; curr_g++)
	{
		if (is_dig(format[curr_g]))
		{
			wd *= 10;
			wd += format[curr_g] - '0';
		}
		else if (format[curr_g] == '*')
		{
			curr_g++;
			wd = va_arg(lt, int);
			break;
		}
		else
			break;
	}

	*g = curr_g - 1;

	return (wd);
}

