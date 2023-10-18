#include "main.h"

/**
 * _putchar - a function that writes c
 * @c: character
 * Return: should be 1 for success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
