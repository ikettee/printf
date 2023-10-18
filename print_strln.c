#include "main.h"
/**
 * _strlen - a function that returns string length
 * @string: the pointer to the string
 * Return: should be g
 */
int _strlen(char *string)
{
	int g;

	for (g = 0; string[g] != 0; g++)
		;
	return (g);
}
/**
 * _strleng - the funct for strlen used for constant char
 * @string: pointer to a chara
 * Return: g
 */
int _strleng(const char *string)
{
	int g;

	for (g = 0; string[g] != 0; g++)
		;
	return (g);
}
