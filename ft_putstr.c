#include "ft_printf.h"

int ft_putstr(char *string)
{
    int index = 0;

    if (string == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (string[index])
    {
        write(1, &string[index], 1);
        index++;
    }
    return (index);
}