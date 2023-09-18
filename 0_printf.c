#include "main.h"

int _printf(const char *format, ...);

/**
 * _printf - functions that produces output according to a format
 * @format: character format that determines the specifier c, s or %
 *
 * Return: Return the number of characters printed
 */

int _printf(const char *format, ...)
{
	int write_character_number = 0, integer_number;
	char character_c, *string1;
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
				string1 = va_arg(write_args_format, char *);
				write_character_number += _print_string(string1);
		}
			else if (*format == '%')
			{
				write(1, "%", 1);
				write_character_number++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				integer_number = va_arg(write_args_format, int);
				write_character_number += _print_integer(integer_number);
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

/**
 * _print_integer - print integer
 * @number1: integer to print
 *
 * Return: number of printed characters
 */

int _print_integer(int number1)
{
	/* declare variable */
	int integer_count1 = 0;
	int count1;
	char buffer[12]; /* buffer for holding integer as a string */

	snprintf(buffer, sizeof(buffer), "%d", number1);

	for (count1 = 0; buffer[count1] != '\0'; count1++)
	{
		write(1, &buffer[count1], 1);
		integer_count1++;
	}

	return (integer_count1);
}
