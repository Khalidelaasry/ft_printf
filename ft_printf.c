#include "ft_printf.h"

int ft_conversion(va_list args, const char specifier)
{
    int printed_count;

    printed_count = 0;
    if (specifier == 'c')
        printed_count += ft_putchar(va_arg(args, int));
    else if (specifier == 's')
        printed_count += ft_putstr(va_arg(args, char *));
    else if (specifier == 'p')
      printed_count += ft_putptr(va_arg(args, uintptr_t));
    else if (specifier == 'd' || specifier == 'i')
        printed_count += ft_putnbr(va_arg(args, int));
    else if (specifier == 'u')
        printed_count += ft_putunsigned(va_arg(args, unsigned int));
    else if (specifier == 'x' || specifier == 'X')
        printed_count += ft_puthex(va_arg(args, unsigned int), specifier);
    else if (specifier == '%')
        printed_count += ft_putchar('%');
    return (printed_count);
}

int ft_printf(const char *text, ...)
{
    int     position;
    va_list args;
    int     total_printed;

    position = 0;
    total_printed = 0;
    va_start(args, text);
    while (text[position])
    {
        if (text[position] == '%')
        {
            total_printed += ft_conversion(args, text[position + 1]);
            position++;
        }
        else
            total_printed += ft_putchar(text[position]);
        position++;
    }
    va_end(args);
    return (total_printed);
}