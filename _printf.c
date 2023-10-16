#include <stdio.h>
#include <stdarg.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    int j = 0;
    va_list args;

    va_start(args, format);
    if (!format || !format[0])
        return -1;

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                char c = va_arg(args, int);
                j += _putchar(c);
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                if (s == NULL) {
                    s = "(null)";
                }
                while (*s) {
                    j += _putchar(*s);
                    s++;
                }
            } else if (*format == '%') {
                j += _putchar('%');
            } else if (*format == 'd' || *format == 'i') {
                int n = va_arg(args, int);
                if (n < 0) {
                    j += _putchar('-');
                    n = -n;
                }
                int count = 1;
                int temp = n;
                while (temp / 10 > 0) {
                    temp /= 10;
                    count *= 10;
                }
                while (count > 0) {
                    j += _putchar((n / count) + '0');
                    n = n % count;
                    count /= 10;
                }
            } else {
                _putchar('%');
                j++;
                if (*format) {
                    _putchar(*format);
                    j++;
                }
            }
            format++;
        } else {
            j += _putchar(*format);
            format++;
        }
    }
    va_end(args);
    return j;
}
