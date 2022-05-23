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
    va_list args;
    va_start(args, format);

    v_printf(format, args);

    va_end(args);
    return (0);
}
