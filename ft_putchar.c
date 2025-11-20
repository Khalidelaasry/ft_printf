#include "ft_printf.h"

int ft_putchar(int character)
{
    write(1, &character, 1);
    return (1);
}