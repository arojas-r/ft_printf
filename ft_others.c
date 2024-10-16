/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:31:52 by arojas-r          #+#    #+#             */
/*   Updated: 2024/10/14 18:31:59 by arojas-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			n = -n;
			return (ft_putunbr (n) + 1);
		}
		return (ft_putunbr(n));
	}
}

int	ft_putnbr_base(unsigned long nbr, char *base, int result)
{
	unsigned long	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr < len_base)
	{
		if (ft_putchar(base[nbr]) == -1)
			return (-1);
		return (result + 1);
	}
	else
	{
		result = ft_putnbr_base(nbr / len_base, base, result);
		if (result == -1)
			return (-1);
		if (ft_putchar(base[nbr % len_base]) == -1)
			return (-1);
		return (result + 1);
	}
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[count])
	{
		if (ft_putchar(s[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = ft_putunbr(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	i++;
	return (i);
}
