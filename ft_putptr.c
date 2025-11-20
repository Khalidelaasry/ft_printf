#include "ft_printf.h"

static void print_ptr(uintptr_t address)
{
    char *base = "0123456789abcdef";

    if (address >= 16)
        print_ptr(address / 16);
    write(1, &base[address % 16], 1);
}

int ft_putptr(uintptr_t address)
{
    int len = 2;

    write(1, "0x", 2);

    if (address == 0)
    {
        write(1, "0", 1);
        return (3);
    }

    print_ptr(address);

    while (address)
    {
        len++;
        address /= 16;
    }
    return (len);
}