#include "main.h"

/**
 * prt_uns - function that print unsign number
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: width
 * @pre: precision
 * @sz: the size
 * Return: chara to print
 */
int prt_uns(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int g = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(typ, unsigned long int);

	numb = c_sz_uns(numb, sz);

	if (numb == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[g--] = (numb % 10) + '0';
		numb /= 10;
	}

	g++;

	return (w_uns(0, g, buffer, flags, wd, pre, sz));
}

/**
 * prt_octa - function that print unsign octa
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: wd
 * @pre: Precision
 * @sz: Size
 * Return: chara to print
 */
int print_octa(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{

	int g = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(typ, unsigned long int);
	unsigned long int ini_numb = numb;

	UNUSED(wd);

	numb = c_sz_uns(numb, sz);

	if (numb == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[g--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && ini_numb != 0)
		buffer[g--] = '0';

	g++;

	return (w_uns(0, g, buffer, flags, wd, pre, sz));
}

/**
 * prt_hexal - function that print hexa
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: width
 * @pre: the precision
 * @sz: the size
 * Return: The number of charas to print
 */
int prt_hexal(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	return (prt_hexa_up(typ, "0123456789abcdef", buffer,
		flags, 'x', wd, pre, sz));
}

/**
 * prt_hexax - function that print upper hexadec
 * @typ: arguments
 * @buffer: buffer array
 * @flags: flags
 * @wd: the width
 * @pre: the precision
 * @sz: the size
 * Return: chara to print
*/
int prt_hexax(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	return (prt_hexa_up(typ, "0123456789ABCDEF", buffer,
		flags, 'X', wd, pre, sz));
}

/**
 * prt_hexa_up - function that print hexadec numb (lower / upper)
 * @typ: arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: flags
 * @wd: width
 * @pre: precision
 * @sz: the size
 * @sz: the size
 * Return: the chara to print
 */
int prt_hexa_up(va_list typ, char map_to[], char buffer[],
	int flags, char flag_ch, int wd, int pre, int sz)
{
	int g = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(typ, unsigned long int);
	unsigned long int ini_numb = numb;

	UNUSED(wd);

	numb = c_sz_uns(numb, sz);

	if (numb == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[g--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && ini_numb != 0)
	{
		buffer[g--] = flag_ch;
		buffer[g--] = '0';
	}

	g++;

	return (w_uns(0, g, buffer, flags, wd, pre, sz));
}

