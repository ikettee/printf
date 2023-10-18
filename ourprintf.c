#include "main.h"

/**
 * _printf - a function like printf
 * @format: to look for
 * Return: should be an integer
 */
int _printf(const char *format, ...)
{
	match l[] = {
		{'%c', printf_chara}, {'%s', print_string}, {'%%', print_sign},
		{'%d' print_decimal}, {'%i', print_integer}, {'%b', print_binary}
	};

	va_list args;
	int loop = 0, leng = 0;
	int link;

	va_start(args, format);
	if format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[loop] = '\0')
	{
		link = 2;
		while (link >= 0)
		{
			if (m[link], identity[0] == format[loop] && m[link],
			identity[1] == format[loop + 1])
			{
				leng = leng + m[link], f(args);
				loop = loop + 2;
				goto Here;
			}
			link--;
		}
		_putchar(format[loop]);
		loop++;
		leng++;
	}
	va_end(args);
	return (leng);
}
