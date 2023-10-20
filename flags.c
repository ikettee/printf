#include "main.h"

/**
 * gt_ac_flags - function to calc flags
 * @format: Format
 * @g: parameter.
 * Return: should be flags
 */
int gt_ac_flags(const char *format, int *g)
{
	int k, curr_g;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_g = *g + 1; format[curr_g] != '\0'; curr_g++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[curr_g] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*g = curr_g - 1;

	return (flags);
}


