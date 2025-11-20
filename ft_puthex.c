#include "ft_printf.h"

static void print_hex(unsigned int value, const char specifier)
{
    char *base;

    if (specifier == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";

    if (value >= 16)
        print_hex(value / 16, specifier);
    write(1, &base[value % 16], 1);
}

int ft_puthex(unsigned int value, const char specifier)
{
    int len = 0;
    unsigned int temp = value;

    print_hex(value, specifier);

    if (value == 0)
        return (1);

    while (temp)
    {
        len++;
        temp /= 16;
    }
    return (len);
}