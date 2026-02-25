/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:55:14 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:27:00 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	f_specifier(char c)
{
	const char	*s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

void	handle_fs(int *count, char spec, va_list args)
{
	if (spec == 'd' || spec == 'i')
		h_int(count, args);
	else if (spec == 'u')
		h_unint(count, args);
	else if (spec == 'c')
		h_char(count, args);
	else if (spec == 's')
		h_str(count, args);
	else if (spec == 'p')
		h_ptr(count, args);
	else if (spec == 'x')
		h_hexd(count, args);
	else if (spec == 'X')
		h_hexu(count, args);
	else if (spec == '%')
	{
		write (1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && f_specifier(format[i + 1]))
		{
			handle_fs(&count, format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end (args);
	return (count);
}
