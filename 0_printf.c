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
	va_list write_args_format;

	va_start(write_args_format, format); /* set arguments into list */
	while (*format) /*iterates through the character */
	{
		if (*format != '%') /* if not % sign, write charater to stdout */
		{
			write(1, format, 1);
			write_character_number++;
		}
		else
		{
			format++; /*move to next character */
			if (*format == 'c') /* check if character is c, s or % */
			{
			character_c = va_arg(write_args_format, int);
			write(1, &character_c, 1);
			write_character_number++;
			}
			else if (*format == 's')
			{
				write_character_number += _print_string(va_arg(write_args_format, char *));
		}
			else if (*format == '%')
			{
				write(1, format, 1);
				write_character_number++;
			}
			else
			{
				write(1, "%", 1);
				write_character_number++;
				write(1, format, 1);
				write_character_number++;
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
		write(1, string, 1);
		count_string++;
		string++;
	}

	return (count_string);
}
