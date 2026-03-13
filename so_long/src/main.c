/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:11:53 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 16:37:57 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/LIBFT/libft.h"
#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"

static int	check_extension(const char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (1);
	else
	{
		ft_printf("Error: Invalid file extension\n");
		return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2 || !check_extension(argv[1]))
		return (1);
	if (!init_game(&vars, argv))
		return (1);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	usleep(100000);
	render_map(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
