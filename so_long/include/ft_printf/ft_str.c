/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:57 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:34:12 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	h_char(int *count, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ff_putchar(count, c);
}

void	h_str(int *count, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		ff_putstr(count, "(null)");
	else
		ff_putstr(count, str);
}
