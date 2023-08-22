#ifndef printf_project
#define printf_project

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchr(char c);
int _printf(const char *format, ...);
void handle_char(va_list args);
void handle_string(va_list args, int *chara_print);
void handle_decimal(va_list args, int *chara_print);

#endif
