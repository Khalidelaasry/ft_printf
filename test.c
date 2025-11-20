#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    printf("----- ORIGINAL printf -----\n");
    a = printf("Char: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned: %u\nHex: %x | %X\nPercent: %%\n",
                'A', "Hello", (void*)12345, -42, 42, 255, 255);
    printf("Original returned: %d\n\n", a);

    printf("----- YOUR ft_printf -----\n");
    b = ft_printf("Char: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned: %u\nHex: %x | %X\nPercent: %%\n",
                'A', "Hello", (void*)12345, -42, 42, 255, 255);
    printf("Your ft_printf returned: %d\n\n", b);

    return (0);
}