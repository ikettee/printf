#include "main.h"

/**
 * _printf - the name of the printf function
 * @format: the format
 * Return: print_ch
 *
 * Coded by Essien and Isaac
 */
int _printf(const char *format, ...)
{
	int print_ch = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%' || (*format++ == '\0'))
		{
			write(1, format - 1, 1);
			print_ch++;
		}
		else if (*format == '%')
		{
			write(1, format++, 1);
			print_ch++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			format++, print_ch++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);
			int str_len = 0;

			while (str[str_len])
				str_len++;
			write(1, str, str_len);
			format++, print_ch += str_len;
		}
	}
	va_end(args);
	return (print_ch);
}

/**
 * main - the main function
 * Return: should be 0
 */
int main(void)
{
	_printf("IsaacEssien\n");
	_printf("%%\n");
	_printf("%s\n", "String");
	_printf("%c\n", 'g');
	return (0);
}
