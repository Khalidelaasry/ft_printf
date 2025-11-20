#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>   // <-- THIS IS REQUIRED FOR uintptr_t

int     ft_printf(const char *text, ...);
int     ft_conversion(va_list args, const char specifier);

int     ft_putchar(int character);
int     ft_putstr(char *string);
int     ft_putnbr(int number);
int     ft_putunsigned(unsigned int value);
int     ft_puthex(unsigned int value, const char specifier);
int     ft_putptr(uintptr_t address);


int     ft_int_length(int number);
int     ft_unsigned_length(unsigned int value);
int     ft_hex_length(unsigned int value);
int     ft_pointer_length(uintptr_t address);

char    *ft_fill_string(char *buffer, unsigned int number, int length);
char    *ft_itoa(int number);
char    *ft_uitoa(unsigned int value);

#endif