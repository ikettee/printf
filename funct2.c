#include "main.h"

/**
 * prt_point - function that prints the value pointer variable
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: width
 * @pre: the precision
 * @sz: the size
 * Return: chara to print
 */
int prt_point(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	char extra_c = 0, padd = ' ';
	int indx = BUFF_SIZE - 2, leng = 2, padd_start = 1; /*length=2 0x */
	unsigned long numb_addre;
	char map_to[] = "0123456789abcdef";
	void *addre = va_arg(typ, void *);

	UNUSED(wd);
	UNUSED(sz);

	if (addre == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(pre);

	numb_addre = (unsigned long)addre;

	while (numb_addre > 0)
	{
		buffer[indx--] = map_to[numb_addre % 16];
		numb_addre /= 16;
		leng++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', leng++;
	else if (flags & F_SPACE)
		extra_c = ' ', leng++;

	indx++;

	/*return (write(1, &buffer[g], BUFF_SIZE - g - 1));*/
	return (w_point(buffer, indx, leng,
		wd, flags, padd, extra_c, padd_start));
}

/**
 * prt_n_prt - the function print ascii code in hexa
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: width
 * @pre: the precision
 * @sz: the size
 * Return: chara to print
 */
int prt_n_prt(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int g = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flags);
	UNUSED(wd);
	UNUSED(pre);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[g] != '\0')
	{
		if (prt(str[g]))
			buffer[g + offset] = str[g];
		else
			offset += app_hexa_cod(str[g], buffer, g + offset);

		g++;
	}

	buffer[g + offset] = '\0';

	return (write(1, buffer, g + offset));
}

/**
 * prt_rever - function that print string in reverse.
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: width
 * @pre: precision
 * @sz: size
 * Return: chara to print
 */

int prt_rever(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	char *str;
	int g, numb = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wd);
	UNUSED(sz);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(pre);

		str = ")Null(";
	}
	for (g = 0; str[g]; g++)
		;

	for (g = g - 1; g >= 0; g--)
	{
		char z = str[g];

		write(1, &z, 1);
		numb++;
	}
	return (numb);
}

/**
 * prt_rot13 - function that print a string
 * @typ: arguments
 * @buffer: buffer array
 * @flags:  flags
 * @wd: the width
 * @pre: the precision
 * @sz: the size
 * Return: the number of chara
 */
int prt_rot13(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	char s;
	char *str;
	unsigned int g, k;
	int numb = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wd);
	UNUSED(pre);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (g = 0; str[g]; g++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[g])
			{
				s = out[k];
				write(1, &s, 1);
				numb++;
				break;
			}
		}
		if (!in[k])
		{
			s = str[g];
			write(1, &s, 1);
			numb++;
		}
	}
	return (numb);
}

