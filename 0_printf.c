#include "main.h"

/**
 * _printf - functions that produces output according to a format
 * @format: character format that determines the specifier c, s or %
 *
 * Return: Return the number of characters printed
 */

int _printf(const char *format, ...)
{
	int write_character_number = 0;
	char character_c;
	va_list write_args_format; /* declare va_list to add as many arguments*/

	if (format == NULL) /* check to see if the character supplied is acceptable */
		return (-1); /* return an error -1 */
	va_start(write_args_format, format); /* set arguments into list */
	while (*format) /*iterates through the character */
	{
		if (*format != '%') /* if not % sign, write charater to stdout */
		{
			write(1, &format, 1);
			write_character_number++;
		}
		else
		{
			format++; /*move to next character */
			/* checking next character to see if it is a null character */
			if (*format == '\0')
				break; /* if true, break the loop and end */
		if (*format == '%')/* checking for conversion specifiers c, s and % */
		{
			write(1, format, 1);
			write_character_number++; /* increment numbers of character printed */
		}
		else if (*format == 'c')
		{
			character_c = va_arg(write_args_format, int);
			write(1, &character_c, 1);
			write_character_number++;
		}
		else if (*format == 's')
		{
			write_character_number += _print_string(va_arg(write_args_format, char *));
		}
		}
		format++;
		}
	va_end(write_args_format);
	return (write_character_number);
}

/**
 * _print_string - print string
 * @string: string to print out
 *
 * Return: numbers of printed characters
 */

int _print_string(char *string)
{
	int count_string = 0;

	if (string == NULL)
	{
		string = "(null)";
	}

	while (*string)
	{
		putchar(*string);
		count_string++;
		string++;
	}

	return (count_string);
}

