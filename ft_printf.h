/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:30:17 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/12 03:23:42 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// To handle variadic arguments in function
# include <stdarg.h>
// Include our libft
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(long n, char *base, int omit_print_neg);

#endif