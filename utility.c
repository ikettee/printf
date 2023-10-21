#include "main.h"

/**
 * is_prt - function that evaluates printable chara
 * @c: evaluated char
 * Return: should be 1 if c is printable, or 0
 */
int is_prt(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * app_hexa_cod - function to append ascci in hexa code
 * @buffer: array
 * @g: the index to start.
 * @ascii_cod: ASSCI code for
 * Return: should be 3
 */
int app_hexa_cod(char ascii_cod, char buffer[], int g)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format code 2 */
	if (ascii_cod < 0)
		ascii_cod *= -1;

	buffer[g++] = '\\';
	buffer[g++] = 'x';

	buffer[g++] = map_to[ascii_cod / 16];
	buffer[g] = map_to[ascii_cod % 16];

	return (3);
}

/**
 * is_dig - a function to find if char is a digit
 * @c: character
 * Return: should be 1 if c is a dig, or 0 if not
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * c_sz_numb - a function that cast a numb to size
 * @numb: the casted number
 * @sz: the number that shows the size
* Return: value of number
 */
long int c_sz_numb(long int numb, int sz)
{
	if (sz == S_LONG)
		return (numb);
	else if (sz == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * c_sz_uns - a function that cast a number to size
 * @numb: the number cast
 * @sz: the number that shows the size
 * Return: value of number
 */
long int c_sz_uns(unsigned long int numb, int sz)
{
	if (sz == S_LONG)
		return (numb);
	else if (sz == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}

