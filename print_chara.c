#include "main.h"

/**
 * print_chara - a function that print characters
 * @args: an argument
 * Return: should be 1
 */
int print_chara(va_list args)
{
	char chara;

	chara = va_arg(args, int);
	_putchar(chara);
	return (1);
}
