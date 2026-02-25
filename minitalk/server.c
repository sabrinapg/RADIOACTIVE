/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:00:00 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:47:56 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "include/LIBFT/libft.h"

static void	handle_signal(int sig)
{
	static int	bit;
	static int	c;

	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
