#include "main.h"

int _printf(const char *format, ...);

/**
 * _putchar - writes character
 * @c: character
 * Return: number of charaters written
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_character - character to print
 * @argument: contains character to print
 *
 * Return: number of char printed
 */

int print_character(va_list argument)
{
	/* declare variable character */
	char character;

	character = va_arg(argument, int);
	return (_putchar(character));
}

/**
 * string_print - print string
 * @argument: va_list that contains the string to print
 *
 * Return: number of characters printed
 */

int string_print(va_list argument)
{
	/* declare variable strings */
	int count1 = 0;
	char *strings;

	strings = va_arg(argument, char *);
	/* check is string is NULL */
	if (strings == NULL)
		strings = "(null)";

	while (*strings)
	{
		_putchar(*strings);
		count1++;
		strings++;
	}
	return (count1);
}

/**
 * int_print - int print
 * @argument: va_list that contains the integer to print
 *
 * Return: number of characters printed
 */

int int_print(va_list argument)
{
	/* declare variable */
	int number1, number_reverse = 0, count2 = 0;

	number1 = va_arg(argument, int);

	if (number1 < 0)
	{
		_putchar('-');
		count2++;
		number1 = -number1;
	}
	if (number1 == 0)
	{
		_putchar('0');
		count2++;
	}
	else
	{
		while (number1 != 0)
		{
			number_reverse = number_reverse * 10 + number1 % 10;
			number1 /= 10;
		}
		while (number_reverse != 0)
		{
			_putchar('0' + number_reverse % 10);
			count2++;
			number_reverse /= 10;
		}
	}
	return (count2);
}

/**
 * _printf - printf custom function
 * @format: format string
 *
 * Return: number of characters returned
 */

int _printf(const char *format, ...)
{
	/* declare variables */
	va_list argument;
	int count3 = 0;

	va_start(argument, format); /* set argument into the va_list */

	while (*format) /* iterate the format string */
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break; /* discontinue and end loop if format is null byte */
			if (*format == 'c')
				count3 += print_character(argument);
			else if (*format == 's')
				count3 += string_print(argument);
			else if (*format == 'd' || *format == 'i')
				count3 += int_print(argument);
			else if (*format == '%')
			{
				_putchar('%');
				count3++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count3 += 2;
			}
		}
		else
		{
			_putchar(*format);
			count3++;
		}
		format++;
	}
	va_end(argument);
	return (count3);
}
