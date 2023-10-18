#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct form
{
	char *identity;
	int (*g)();
} match;

int _putchar(char c);
int print_chara(va_list args);
int print_string(va_list args);
int _strlen(char *string);
int _strleng(const char *string);
int print_sign(void);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_binary(va_list args);
int _printf(const char *format, ...);

#endif
