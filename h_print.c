#include "main.h"
/**
 * h_prt - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @lt: arguments.
 * @indx: ind.
 * @buffer: Buffer array
 * @flags: what is the active flags
 * @wd: get wd
 * @pre: the precision
 * @sz: the size
 * Return: 1 or 2;
 */
int h_prt(const char *fmt, int *indx, va_list lt, char buffer[],
	int flags, int wd, int pre, int sz)
{
	int g, unkn_len = 0, prt_chara = -1;
	fmt_t fmt_types[] = {
		{'c', prt_chara}, {'s', prt_string}, {'%', prt_sign},
		{'i', prt_integer}, {'d', prt_integer}, {'b', prt_binary},
		{'u', prt_uns}, {'o', prt_octa}, {'x', prt_hexal},
		{'X', prt_hexax}, {'p', prt_point}, {'S', prt_n_prt},
		{'r', prt_rever}, {'R', prt_rot13}, {'\0', NULL}
	};
	for (g = 0; fmt_types[g].fmt != '\0'; g++)
		if (fmt[*indx] == fmt_types[g].fmt)
			return (fmt_types[g].fn(lt, buffer, flags, wd, pre, sz)
);

	if (fmt_types[g].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		unkn_len += write(1, "%%", 1);
		if (fmt[*indx - 1] == ' ')
			unkn_len += write(1, " ", 1);
		else if (wd)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*indx] != '%')
				--(*indx);
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unkn_len += write(1, &fmt[*indx], 1);
		return (unkn_len);
	}
	return (prt_chara);
}

