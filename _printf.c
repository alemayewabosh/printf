#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "main.h"

/**
 * unsigned_integer_to_string - changes the unsigned integer to string
 * @integer: integer number
 * @base: takes in the desired base to print with
 * @buffer: charachter array
 * Return: returns nothing
 */

void unsigned_integer_to_string(uint64_t integer, int base, char *buffer)
{
	int i, digit, cur = 0;
	char _buffer[40];

	if (integer == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	for (i = 0; i < 40; i++)
		_buffer[i] = 0;
	while (integer)
	{
		digit = integer % base;
		if (digit >= 10)
			_buffer[cur++] = 'a' + (digit - 10);
		else if (digit >= 10)
			_buffer[cur++] = 'A' + (digit - 10);
		else
			_buffer[cur++] = '0' + digit;
		integer /= base;
	}

	for (i = cur - 1; i != 0; i--)
		*buffer++ = _buffer[i];
	*buffer++ = _buffer[0];
	*buffer = 0;
}

/**
 * signed_integer_to_string - changes the signed integer to string
 * @integer: integer number
 * @base: takes in the desired base to print with
 * @buffer: charachter array
 * Return: returns nothing
 */

void signed_integer_to_string(int64_t integer, int base, char *buffer)
{
	if (integer < 0)
	{
		*buffer++ = '-';
		integer = -integer;
	}
	unsigned_integer_to_string(integer, base, buffer);
}

/**
 * switchFunction - switchs cases of format specifiers
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */

/*State: 0: regular 1: escape*/

void switchFunction(const char *format, va_list args)
{
	const char *s;

	switch (*format)
	{
	case 'c':
		_putchar((va_arg(args, int)));
		break;
	case 's':
	{
		s = va_arg(args, const char *);
		while (*s)
			_putchar(*s++);
		break;
	}
	case '%':
		_putchar('%');
		break;
	case 'd':
		printBuffer(10, args);
		break;
	case 'i':
		printBuffer(10, args);
		break;
	case 'b':
		printBuffer(2, args);
		break;
	default:
	break;
	}
}
/**
 * v_printf - checks if a percentage specifier is
 *            there and prints
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */

void v_printf(const char *format, va_list args)
{
	int state = 0;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
				_putchar(*format);
		}
		else if (state == 1)
		{
			switchFunction(format, args);
			state = 0;
		}
		format++;
	}
}

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 *         (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int noSpecifier = 1, length = 0, isPercentage = 0;
	const char *s = format, *s1 = format;
	va_list args;

	while (*s1)
	{
		if (*s1 == '%')
		{
			noSpecifier = 0;
			break;
		}
		s1++;
	}
	while (*s1)
	{
		if (*s1 == '%' && *(s1 + 1) == '%')
			isPercentage = 1;
		s1++;
	}
	va_start(args, format);
	if (!noSpecifier)
		v_printf(format, args);
	else
	{
		while (*s)
		{
			_putchar(*s);
			s++;
		}
		_strlen(format, isPercentage);
	}
	va_end(args);
	for (length = 0; *format != '\0'; format++)
		length++;
	if (isPercentage)
		return (length - 1);
	else
		return (length);
}
