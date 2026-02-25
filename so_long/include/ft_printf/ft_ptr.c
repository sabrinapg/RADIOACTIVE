/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:31 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:36:35 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	h_ptr(int *count, va_list args)
{
	unsigned long long	ptr;

	ptr = va_arg(args, unsigned long long);
	if (ptr == 0)
	{
		ff_putstr(count, "(nil)");
		return ;
	}
	ff_putstr(count, "0x");
	ff_putnbr_base(count, ptr, "0123456789abcdef");
}
