#include "ft_printf.h"

static void print_unsigned_number(unsigned int value)
{
    char digit;

    if (value >= 10)
        print_unsigned_number(value / 10);
    digit = (value % 10) + '0';
    write(1, &digit, 1);
}

int ft_putunsigned(unsigned int value)
{
    int len = 0;
    unsigned int temp = value;

    print_unsigned_number(value);

    if (value == 0)
        return (1);

    while (temp)
    {
        len++;
        temp /= 10;
    }
    return (len);
}