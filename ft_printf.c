/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:32:36 by arojas-r          #+#    #+#             */
/*   Updated: 2024/10/14 19:07:24 by arojas-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_pointer(unsigned long p)
{
	int	result;
	int	hex;

	if (!p)
		return (ft_putstr("(nil)"));
	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	hex = ft_putnbr_base(p, "0123456789abcdef", 0);
	if (hex == -1)
		return (-1);
	return (result + hex);
}

int	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_hex_pointer(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 0));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 0));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_format(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (*(format + *i) == '%' && *(format + *i + 1) != '\0')
	{
		(*i)++;
		count = ft_check_format(*(format + *i), args);
		if (count == -1)
			return (-1);
	}
	else if (*(format + *i) != '%')
	{
		count = ft_putchar(*(format + *i));
		if (count == -1)
			return (-1);
	}
	(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	va_start(args, format);
	i = 0;
	count = 0;
	result = 0;
	if (format)
	{
		while (*(format + i))
		{
			result = ft_format(format, args, &i);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int main(void)
{
    char *str = "Razer, Kraken, Kitty";
    int num = 42;
    unsigned int unum = 42;
    void *ptr = &num;
	int len;

    ft_printf("un carácter: %c\n", 'A');
	printf("un carácter: %c\n", 'A');
    ft_printf("una cadena: %s\n", str);
	printf("una cadena: %s\n", str);
    ft_printf("El puntero se imprime en hexadecimal: %p\n", ptr);
	printf("El puntero se imprime en hexadecimal: %p\n", ptr);
    ft_printf("un número decimal en base 10: %d\n", num);
	printf("un número decimal en base 10: %d\n", num);
    ft_printf("un entero en base 10: %i\n", num);
	printf("un entero base 10: %i\n", num);
	ft_printf("un número decimal en base 10 sin signo: %u\n", unum);
	printf("un numero decimal en base 10 sin signo: %u\n", unum);
    ft_printf("un número hexadecimal en base 16 en minúsculas: %x\n", num);
    printf("numero hexadecimal en base 16 en minuculas: %x\n", num);
	ft_printf("un número hexadecimal en base 16 en mayúsculas: %X\n", num);
    printf("numero hexadecimal en base 16 en mayusculas: %X\n", num);
	ft_printf("símbolo del porcentaje: %%\n");
	printf("simbolo del porcentaje: %%\n");
	ft_printf("hola soy %s, y tengo %d años.\n", "Anais", 22);
	printf("hola soy %s, y tengo %d años.\n", "Anais", 22);
	ft_printf("%c %s %p %d %i %u %x %X\n", 
	'a', "hola", ptr, num, num, num, num, num);
	printf("%c %s %p %d %i %u %x %X\n", 
	'a', "hola", ptr, num, num, num, num, num);

    return 0;
}*/