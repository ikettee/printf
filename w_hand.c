#include "main.h"

/**
 * h_write_chara - function that print a string
 * @c: character
 * @buffer: buffer array
 * @flags: flags
 * @wd: to get width
 * @pre: the precision
 * @sz: the size
 * Return: the number of characters
 */
int h_write_chara(char c, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int g = 0;
	char padd = ' ';

	UNUSED(pre);
	UNUSED(sz);

	if (flags & F_ZERO)
		padd = '0';

	buffer[g++] = c;
	buffer[g] = '\0';

	if (wd > 1)
{
		buffer[BUFF_SIZE - 1] = '\0';
		for (g = 0; g < wd - 1; g++)
			buffer[BUFF_SIZE - g - 2] = padd;

		if (flags & F_MINUS)
		return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - g - 1], wd - 1));
		else
		return (write(1, &buffer[BUFF_SIZE - g - 1], wd - 1) +
				write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * w_numb - function that prints a string
 * @negat: arguments
 * @indx: character types.
 * @buffer: buffer array
 * @flags:  flags
 * @wd: for the width.
 * @pre: the precision
 * @sz: the size
*
 * Return: Number of chara print
 */
int w_numb(int negat, int indx, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int leng = BUFF_SIZE - indx - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(sz);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (negat)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (w_numb2(indx, buffer, flags, wd, pre,
		leng, padd, extra_ch));
}
/**
 * w_numb2 - function that write a number
 * @indx: Index at which the number starts
 * @buffer: Buffer
 * @flags: Flags
 * @wd: width
 * @pre: precision
 * @leng: the length
 * @padd: Pading character
 * @extra_c: Extra character
 *
 * Return: print character.
 */
int w_numb2(int indx, char buffer[],
	int flags, int wd, int pre,
	int leng, char padd, char extra_c)
{
	int g, padd_start = 1;

	if (pre == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && wd == 0)
		return (0); /* printf(".0d", 0)  no chara will be printed */
	if (pre == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = padd = ' '; /* the width is displayed padding ' ' */
	if (pre > 0 && pre < leng)
		padd = ' ';
	while (pre > leng)
		buffer[--indx] = '0', leng++;
	if (extra_c != 0)
		leng++;
	if (wd > leng)
	{
		for (g = 1; g < wd - leng + 1; g++)
			buffer[g] = padd;
		buffer[g] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Assign extra chara to left of buffer */
		{
			if (extra_c)
				buffer[--indx] = extra_c;
		return (write(1, &buffer[indx], leng) + write(1, &buffer[1], g - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra chara to left of buff */
		{
			if (extra_c)
				buffer[--indx] = extra_c;
		return (write(1, &buffer[1], g - 1) + write(1, &buffer[indx], leng));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra chara to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
		return (write(1, &buffer[padd_start], g - padd_start) +
			write(1, &buffer[indx], leng - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--indx] = extra_c;
	return (write(1, &buffer[indx], leng));
}

/**
 * write_uns - a function that writes unsign number
 * @negat: the number negative
 * @indx: the index
 * @buffer: Array of chara
 * @flags: Flags
 * @wd: width
 * @pre: the precision
 * @sz: size
 * Return: written chara
 */
int write_uns(int negat, int indx,
	char buffer[],
int flags, int wd, int pre, int sz)
{
	/* stored at the bufer's right and starts at position g */
	int leng = BUFF_SIZE - indx - 1, g = 0;
	char padd = ' ';

	UNUSED(negat);
	UNUSED(sz);

	if (pre == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0); /* printf(".0d", 0)  no chara is printed */

	if (pre > 0 && pre < leng)
		padd = ' ';

	while (pre > leng)
	{
		buffer[--indx] = '0';
		leng++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (wd > leng)
	{
		for (g = 0; g < wd - leng; g++)
			buffer[g] = padd;

		buffer[g] = '\0';

		if (flags & F_MINUS) /* Assign extra chara to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[indx], leng) + write(1, &buffer[0], g));
		}
		else /* Assign extra chara to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], g) + write(1, &buffer[indx], leng));
		}
	}

	return (write(1, &buffer[indx], leng));
}

/**
 * write_point - a function that write to memory address
 * @buffer: Arrays of charact
 * @indx: Index at which the number starts
 * @leng: the length of number
 * @wd: width
 * @flags: Flags
 * @padd: padding
* @extra_c: extra char
 * @padd_start: padding should start
 *
 * Return: written character
 */
int write_point(char buffer[], int indx, int leng,
	int wd, int flags, char padd, char extra_c, int padd_start)
{
	int g;

	if (wd > leng)
	{
		for (g = 3; g < wd - leng + 3; g++)
			buffer[g] = padd;
		buffer[g] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Assign extra char*/
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
		return (write(1, &buffer[indx], leng) + write(1, &buffer[3], g - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra chara to left */
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
		return (write(1, &buffer[3], g - 3) + write(1, &buffer[indx], leng));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra chara to left */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
		return (write(1, &buffer[padd_start], g - padd_start) +
			write(1, &buffer[indx], leng - (1 - padd_start) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (extra_c)
		buffer[--indx] = extra_c;
	return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}

