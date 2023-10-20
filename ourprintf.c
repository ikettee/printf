#include "main.h"

void prt_buf(char buf[], int *buf_in);

/**
 * _printf - A function for Printf
 * @format: the format of printf
 * Return: Should be printed chara
 */
int _printf(const char *format, ...)
{
	int g, prt = 0, prt_chara = 0;
	int fl, wd, pre, sz, buf_in = 0;
	va_list lst;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (g = 0; format && format[g] != '\0'; g++)
	{
		if (format[g] != '%')
		{
			buf[buf_in++] = format[g];
			if (buf_in == BUFF_SIZE)
				prt_buf(buf, &buf_in);
			/* write(1, &format[g], 1);*/
			prt_chara++;
		}
		else
		{
			prt_buf(buf, &buf_in);
			fl = gt_ac_flags(format, &g);
			wd = get_wd(format, &g, lst);
			pre = get_pre(format, &g, lst);
			sz = get_sz(format, &g);
			++g;
			prt = h_prt(format, &g, lst, buf,
				fl, wd, pre, sz);
			if (prt == -1)
				return (-1);
			prt_chara += prt;
		}
	}

	prt_buf(buf, &buf_in);

	va_end(lst);

	return (prt_chara);
}

/**
 * prt_buf - a function to print the content of a buffer
 * @buf: Chara array
 * @buf_in: the index for the next chara.
 */
void prt_buf(char buf[], int *buf_in)
{
	if (*buf_in > 0)
		write(1, &buf[0], *buf_in);

	*buf_in = 0;
}

