#include <stdio.h>
#include <stdarg.h>

char what_is_next(char * format){
    format = format + 1;
    return * format;
}

void print_int(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
        print_int(n / 10);
    putchar(n % 10 + '0');
}

void print_double(double d)
{
    int int_part = (int)d;
    double frac_part = d - int_part;

    print_int(int_part);
    putchar('.');

    int i;
    for (i = 0; i < 6; i++) {
        frac_part *= 10;
        int digit = (int)frac_part;
        putchar(digit + '0');
        frac_part -= digit;
    }
}


void myprintf(const char *format, ...)
{
    va_list ap;
    char c;

    va_start(ap, format);
    while (c = *format++) {
	    if (c == '%') {
            char next = *format++;   // 读取格式符并跳过
            switch (next) {
                case 'd': {
                    int n = va_arg(ap, int);
                    print_int(n);
                    break;
                }
                case 'f': {
                    double d = va_arg(ap, double);
                    print_double(d);
                    break;
                }
                case 'c': {
                    char ch = (char)va_arg(ap, int);
                    putchar(ch);
                    break;
                }
                case 's': {
                    char *p = va_arg(ap, char *);
                    while (*p)
                        putchar(*p++);
                    break;
                }
                case '%': {
                    putchar('%');
                    break;
                }
                default: {
                    putchar('%');
                    putchar(next);
                    break;
                }
            }
        } else {
            putchar(c);
        }
    }
    va_end(ap);
}

int main(void)
{
     myprintf("c\ts\n", '1', "hello");
     return 0;
}