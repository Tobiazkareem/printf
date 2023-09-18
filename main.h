#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * _printf - prinf custom function
 * @format: string to format
 *
 * Return: return the number of characters
 */

int _printf(const char *format, ...);
int _print_string(char *string);
int int_print(va_list argument);
int string_print(va_list argument);
int print_character(va_list argument);
int _putchar(char c);

#endif
