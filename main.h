#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>
#include <stdarg.h>
void _putchar(char c);
int _strlen(const char *s, int flag);
void unsigned_integer_to_string(uint64_t integer, int base, char *buffer);
void signed_integer_to_string(int64_t integer, int base, char *buffer);
void printBuffer(int base, va_list args);
int _printf(const char *format, ...);

#endif /*#ifndef MAIN_H*/
