/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:47:30 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:49:43 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/LIBFT/libft.h"

static volatile int	g_ack = 0;

static void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_bit(int pid, int bit)
{
	g_ack = 0;
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	while (!g_ack)
		pause();
}

static void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (c >> bit) & 1);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Usage: ./client_bonus <PID> <message>\n", 38);
		return (1);
	}
	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
