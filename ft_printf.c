/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:14:10 by aprado            #+#    #+#             */
/*   Updated: 2023/11/24 10:56:10 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	core_printf(char format, va_list arguments)
{
	int	number;

	number = 0;
	if (format == 'c')
		number = ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		number = ft_putstr(va_arg(arguments, char *));
	else if (format == 'i')
		number = ft_putnbr(va_arg(arguments, int));
	else if (format == 'd')
		number = ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		number = ft_putunbr(va_arg(arguments, unsigned int));
	else if (format == 'x')
		number = ft_dectohex(va_arg(arguments, unsigned int), format);
	else if (format == 'X')
		number = ft_dectohex(va_arg(arguments, unsigned int), format);
	else if (format == 'p')
		number = ft_dectohex(va_arg(arguments, unsigned long long), format);
	else if (format == '%')
		number = ft_putchar('%');
	return (number);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		number_ch;

	if (!format)
		return (0);
	number_ch = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			number_ch += core_printf(*format, arguments);
		}
		else
			number_ch += ft_putchar(*format);
		format++;
	}
	va_end(arguments);
	return (number_ch);
}
