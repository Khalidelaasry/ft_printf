#include "ft_printf.h"

static void print_number(long num)
{
    char digit;

    if (num >= 10)
        print_number(num / 10);
    digit = (num % 10) + '0';
    write(1, &digit, 1);
}

int ft_putnbr(int number)
{
    long num = number;
    int length = 0;

    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
        length++;
    }
    print_number(num);

    while (number)
    {
        length++;
        number /= 10;
    }
    if (num == 0)
        return (1);
    return (length);
}