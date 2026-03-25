/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:58:47 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:32:26 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ff_putchar(int *count, char c)
{
	write(1, &c, 1);
	(*count)++;
}

void	ff_putstr(int *count, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ff_putchar(count, s[i++]);
}

void	ff_putnbr_base(int *count, unsigned long long nbr, const char *base)
{
	char	buffer[20];
	int		base_len;
	int		i;

	base_len = 0;
	i = 0;
	while (base[base_len])
		base_len++;
	if (nbr == 0)
	{
		ff_putstr(count, "0");
		return ;
	}
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (--i >= 0)
		ff_putchar(count, buffer[i]);
}
