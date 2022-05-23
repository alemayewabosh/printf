#include "main.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

void v_printf(const char *format, va_list args){
    int state = 0;

    while (*format)
    {
        if (state == 0){
            if (*format == '%'){
                state = 1;
            }
            else {
                putchar(*format);
                
                }
            }
            else if (state == 1){
                switch (*format)
                {
                case 'd':{
                    int n = va_arg (args, int);
                    putchar(n);
                    break;}
                
                case 'u':
                    break;
                case 'o':
                    break;
                
                case 'x':
                    break;
                case'X':
                    break;
                
                case 'c':{
                    char ch = va_arg(args, int);
                    putchar(ch);
                    break;}
                case 's':{
                    const char *s = va_arg(args, char *);
                    putchar(*s++);
                    break;
                }
                case 'p':
                    break;
                         
                case 'r':
                    break;
                }
                state = 0;
            }
            format++;
    }
}
    
/**
 * @brief printf will print the characters
 * 
 * @param format format
 * @param ... 
 * @return int intiger
 */

int _printf(const char *format, ...){
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
			putchar(*s++);
	}
	va_end(args);
	for (length = 0; *format != '\0'; format++)
		length++;
	if (isPercentage)
		return (length - 1);
	else
		return (length);
}
