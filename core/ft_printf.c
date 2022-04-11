/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:46:54 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/12 00:49:49 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define HEX_LOW "0123456789abcdef"
#define HEX_UPP "0123456789ABCDEF"
#define DEC_DEF "0123456789"

static int	matches_mask(const char **__format, char mask)
{
	char	*format;

	format = (char *)*__format;
	if (*format == '%' && format[1] == mask)
		return (++*__format, 1);
	return (0);
}

static int	puts_nbr(const char **format, va_list args, size_t *printed)
{
	int	result;

	result = 0;
	if (matches_mask(format, 'p'))
	{
		ft_putstr_fd("0x", 1);
		result = 2 + ft_putnbr_base(va_arg(args, size_t), HEX_LOW);
	}
	else if (matches_mask(format, 'd'))
		result = ft_putnbr_base(va_arg(args, long), DEC_DEF);
	else if (matches_mask(format, 'i'))
		result = ft_putnbr_base(va_arg(args, int), DEC_DEF);
	else if (matches_mask(format, 'u'))
		result = ft_putnbr_base(va_arg(args, size_t), DEC_DEF);
	else if (matches_mask(format, 'x'))
		result = ft_putnbr_base(va_arg(args, size_t), HEX_LOW);
	else if (matches_mask(format, 'X'))
		result = ft_putnbr_base(va_arg(args, size_t), HEX_UPP);
	return (*printed += result, result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	printed;
	char	*str;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (matches_mask(&format, 'c') && ++printed)
			ft_putchar_fd(va_arg(args, int), 1);
		else if (matches_mask(&format, 's'))
		{
			printed += ft_strlen((str = va_arg(args, char *)));
			ft_putstr_fd(str, 1);
		}
		else if (puts_nbr(&format, args, &printed))
			;
		else if (matches_mask(&format, '%') && ++printed)
			ft_putchar_fd('%', 1);
		else
			ft_putchar_fd(*format, ++printed && 1);
		format++;
	}
	return (va_end(args), printed);
}
