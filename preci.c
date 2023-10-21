#include "main.h"

/**
 * get_pre - the precision printed
 * @format: formatted arguments
 * @g: arguments
 * @lt: list argument.
 *
 * Return: pre.
 */
int get_pre(const char *format, int *g, va_list lt)
{
	int curr_g = *g + 1;
	int pre = -1;

	if (format[curr_g] != '.')
		return (pre);

	pre = 0;
	for (curr_g += 1; format[curr_g] != '\0'; curr_g++)
	{
		if (is_dig(format[curr_g]))
		{
			pre *= 10;
			pre += format[curr_g] - '0';
		}
		else if (format[curr_g] == '*')
		{
			curr_g++;
			pre = va_arg(lt, int);
			break;
		}
		else
			break;
	}

	*g = curr_g - 1;

	return (pre);
}

