#include "main.h"

/**
 * prt_chara - a function that prints a chara
 * @typ: arguments
 * @buffer: Buffer array
 * @flags:  flags calculated
 * @wd: the Width
 * @pre: the Precision
 * @sz: the Size
 * Return: the num of chara
 */
int prt_chara(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	char c = va_arg(typ, int);

	return (h_write_chara(c, buffer, flags, wd, pre, sz));
}

/**
 * prt_string - a function that Prints a string
 * @typ: arguments
 * @buffer: Buffer array
 * @flags:  flags to calculate
 * @wd: width
 * @pre: The Precision
 * @sz: Size
 * Return: the num of chara
 */
int prt_string(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int leng = 0, g;
	char *str = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wd);
	UNUSED(pre);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (pre >= 0 && pre < leng)
		leng = pre;

	if (wd > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], leng);
			for (g = wd - leng; g > 0; g--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (g = wd - leng; g > 0; g--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (wd);
		}
	}

	return (write(1, str, leng));
}

/**
 * prt_sign - a function that Prints a sign
 * @typ: arguments
 * @buffer: Buffer array
 * @flags:  flags
 * @wd: width.
 * @pre: Precision
 * @sz: Size
 * Return: printed chara
 */
int prt_sign(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	UNUSED(typ);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wd);
	UNUSED(pre);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/**
 * prt_integer - a function that Print int
 * @typ: arguments
 * @buffer: Buffer array
 * @flags:  flags
 * @wd: width.
 * @pre: Precision
 * @sz: Size
 * Return: chars printed
 */
int prt_integer(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int g = BUFF_SIZE - 2;
	int negat = 0;
	long int n = va_arg(typ, long int);
	unsigned long int numb;

	n = c_sz_numb(n, sz);

	if (n == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		negat = 1;
	}

	while (numb > 0)
	{
		buffer[g--] = (numb % 10) + '0';
		numb /= 10;
	}

	g++;

	return (w_numb(negat, g, buffer, flags, wd, pre, sz));
}

/**
 * prt_binary - a function that Prints unsigned number
 * @typ: arguments
 * @buffer: Buffer array
 * @flags:  flags
 * @wd: width
 * @pre: Precision
 * @sz: Size
 * Return: Numbers of chara
 */
int prt_binary(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz)
{
	unsigned int no, mo, g, amt;
	unsigned int k[32];
	int numb;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wd);
	UNUSED(pre);
	UNUSED(sz);

	no = va_arg(typ, unsigned int);
	mo = 2147483648; /* (2 ^ 31) */
	k[0] = no / mo;
	for (g = 1; g < 32; g++)
	{
		mo /= 2;
		k[g] = (no / mo) % 2;
	}
	for (g = 0, amt = 0, numb = 0; g < 32; g++)
	{
		amt += k[g];
		if (amt || g == 31)
		{
			char z = '0' + k[g];

			write(1, &z, 1);
			numb++;
		}
	}
	return (numb);
}

