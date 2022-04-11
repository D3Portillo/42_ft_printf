/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:46:17 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/12 00:42:54 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parses(size_t n, size_t base_size, char **base, int count)
{
	if (n < base_size)
		return (ft_putchar_fd((*base)[n], 1), count + 1);
	return (
		parses(n % base_size, base_size, base,
			parses(n / base_size, base_size, base, count)
		)
	);
}

int	ft_putnbr_base(long n, char *base)
{
	if (n < 0 && write(1, "-", 1))
		n *= -1;
	return (parses(n, ft_strlen(base), &base, 0));
}
