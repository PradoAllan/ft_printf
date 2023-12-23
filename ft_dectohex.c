/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:20:32 by aprado            #+#    #+#             */
/*   Updated: 2023/11/24 10:54:49 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	is_big_letter(unsigned int n)
{
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else
		return ('F');
}

static char	is_letter(unsigned int n, int ch)
{
	if (ch == 120 || ch == 112)
	{
		if (n == 10)
			return ('a');
		else if (n == 11)
			return ('b');
		else if (n == 12)
			return ('c');
		else if (n == 13)
			return ('d');
		else if (n == 14)
			return ('e');
		else
			return ('f');
	}
	else
		return (is_big_letter(n));
}

static int	ft_ptr(unsigned long long n, int ch)
{
	int	char_num;

	char_num = 0;
	if (ch == 112)
	{
		if (n == 0)
		{
			char_num += ft_putstr("(nil)");
			return (char_num);
		}
		char_num += ft_putstr("0x");
	}
	return (char_num);
}

int	ft_dectohex(unsigned long long n, int ch)
{
	int				i;
	int				char_num;
	unsigned int	temp;
	char			array[16];

	i = 1;
	char_num = 0;
	if (ch == 112)
		char_num += ft_ptr(n, ch);
	if (n == 0 && (ch == 'x' || ch == 'X'))
		char_num += ft_putchar('0');
	while (n > 0)
	{
		temp = n % 16;
		n /= 16;
		if (temp < 10)
			array[i++] = temp + '0';
		else
			array[i++] = is_letter(temp, ch);
		temp = n;
	}
	i -= 1;
	while (i > 0)
		char_num += ft_putchar(array[i--]);
	return (char_num);
}

/*
int	main(void)
{
	
	ft_dectohex(540, 'x');
	ft_putchar('\n');
	ft_dectohex(42, 'x');
	ft_putchar('\n');
	ft_dectohex(0, 'x');
	ft_putchar('\n');
	ft_dectohex(45896, 'x');
	ft_putchar('\n');
	printf(": %x :\n", 540);
	printf(": %x :\n", 42);
	printf(": %x :\n", 0);
	printf(": %x :\n", 45896);
	return (0);
}
*/
