/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:01:52 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:40:27 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	h_hexd(int *count, va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
		ff_putstr(count, "0");
	else
		ff_putnbr_base(count, num, "0123456789abcdef");
}

void	h_hexu(int *count, va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
		ff_putstr(count, "0");
	else
		ff_putnbr_base(count, num, "0123456789ABCDEF");
}
