#include "main.h"

/**
 * print_string - a function to print string
 * @args: the arguments
 * Return: string length
 */

int print_string(va_list args)
{
	char *string;
	int g;
	int le;

	string = va_arg(args, char *);
	if (string == NULL)
	{
		string = "(null)";
		le = _strlen(string);
		for (g = 0; i < le; g++)
			_putchar(string[g]);
		return (le);
	}
	else
	{
		le = _strlen(string);
		for (g = 0; g < le; g++)
			_putchar(string[g]);
		return (le);
	}
}

