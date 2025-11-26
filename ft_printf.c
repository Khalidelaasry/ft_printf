/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelaasr <khelaasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:31:04 by khelaasr          #+#    #+#             */
/*   Updated: 2025/11/24 13:39:58 by khelaasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list args, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		total;
	va_list	args;

	index = 0;
	total = 0;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			total += ft_conversion(args, format[index + 1]);
			index++;
		}
		else
			total += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (total);
}
