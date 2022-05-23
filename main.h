#ifndef MAIN_H
#define MAIN_H
#define va_arg(v,l) __builtin_va_arg(v,l)
int _printf(const char *format, ...);


#endif
