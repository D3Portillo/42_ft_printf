/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:46:54 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/11 16:55:36 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	matches_mask(const char **__format, char mask)
{
	char	*format;

	format = (char *)*__format;
	if (*format == '%' && format[1] && format[1] == mask)
		return (++*__format, 1);
	return (0);
}

// c s p d i u x X %
int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (matches_mask(&format, 'c'))
			write(1, "CC", 2);
		else if (matches_mask(&format, 's'))
			write(1, "SS", 2);
		else if (matches_mask(&format, 'p'))
			write(1, "PP", 2);
		else if (matches_mask(&format, 'd'))
			write(1, "DD", 2);
		else if (matches_mask(&format, 'i'))
			write(1, "II", 2);
		else if (matches_mask(&format, 'u'))
			write(1, "UU", 2);
		else if (matches_mask(&format, 'x'))
			write(1, "xx", 2);
		else if (matches_mask(&format, 'X'))
			write(1, "XX", 2);
		else if (matches_mask(&format, '%'))
			write(1, "%", 1);
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}