/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:46:54 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/12 03:33:28 by dcerrito         ###   ########.fr       */
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
	int		result;

	result = 0;
	if (matches_mask(format, 'p'))
		result = (ft_putstr_fd("0x", 1), 2)
			+ ft_putnbr_base(va_arg(args, size_t), HEX_LOW, 1);
	else if (matches_mask(format, 'd'))
		result = ft_putnbr_base(va_arg(args, int), DEC_DEF, 0);
	else if (matches_mask(format, 'i'))
		result = ft_putnbr_base(va_arg(args, int), DEC_DEF, 0);
	else if (matches_mask(format, 'u'))
		result = ft_putnbr_base(va_arg(args, unsigned int), DEC_DEF, 0);
	else if (matches_mask(format, 'x'))
		result = ft_putnbr_base(va_arg(args, unsigned int), HEX_LOW, 0);
	else if (matches_mask(format, 'X'))
		result = ft_putnbr_base(va_arg(args, unsigned int), HEX_UPP, 0);
	return (*printed += result, result);
}

size_t	puts_str(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1), 6);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (matches_mask(&format, 'c') && ++printed)
			ft_putchar_fd(va_arg(args, int), 1);
		else if (matches_mask(&format, 's'))
			printed += puts_str(va_arg(args, char *));
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
