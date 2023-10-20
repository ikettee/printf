#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* THE FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* THE SIZE */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Structure
 *
 * @fmt: format
 * @fn: associate funct
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Structure
 *
 * @fmt: format of
 * @fm_t: The associate funct
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int h_prt(const char *fmt, int *g,
va_list lt, char buffer[], int flags, int wd, int pre, int sz);

/***THE FUNCTIONS ***/

/* print chara and string */
int prt_chara(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_string(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_sign(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

/* print numb */
int prt_integer(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_binary(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_uns(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_octa(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_hexal(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);
int prt_hexax(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

int prt_hexa_up(va_list typ, char map_to[],
char buffer[], int flags, char flag_ch, int wd, int pre, int sz);

/* print non printable chara */
int prt_n_prt(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

/* print address */
int prt_point(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

/* Funciotns for others */
int gt_ac_flags(const char *format, int *g);
int get_wd(const char *format, int *g, va_list lt);
int get_pre(const char *format, int *g, va_list lt);
int get_sz(const char *format, int *g);

/*print string in a rever*/
int prt_rever(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

/*print string rot 13*/
int prt_rot13(va_list typ, char buffer[],
	int flags, int wd, int pre, int sz);

/* handle width */
int h_write_chara(char c, char buffer[],
	int flags, int wd, int pre, int sz);
int w_numb(int posit, int indx, char buffer[],
	int flags, int wd, int pre, int sz);
int w_numb2(int indx, char bff[], int flags, int width, int precision,
	int leng, char padd, char extra_c);
int w_point(char buffer[], int indx, int leng,
	int wd, int flags, char padd, char extra_c, int padd_start);

int w_uns(int negat, int indx,
char buffer[],
	int flags, int wd, int pre, int sz);

/*** THE UTIL ***/
int prt(char);
int app_hexa_cod(char, char[], int);
int is_dig(char);

long int c_sz_numb(long int numb, int sz);
long int c_sz_uns(unsigned long int numb, int sz);

#endif /* THE MAIN_H */

