/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:15 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:43:34 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ff_putnbr(int *count, int nb)
{
	if (nb == -2147483648)
	{
		ff_putstr(count, "-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ff_putchar(count, '-');
		nb = -nb;
	}
	if (nb >= 10)
		ff_putnbr(count, nb / 10);
	ff_putchar(count, (nb % 10) + '0');
}

void	ff_putnbr2(int *count, unsigned int nb)
{
	if (nb >= 10)
		ff_putnbr2(count, nb / 10);
	ff_putchar(count, (nb % 10) + '0');
}

void	h_int(int *count, va_list args)
{
	int	n;

	n = va_arg(args, int);
	ff_putnbr(count, n);
}

void	h_unint(int *count, va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ff_putnbr2(count, n);
}
