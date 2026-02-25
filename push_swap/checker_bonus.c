/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:51:46 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		do_sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		do_sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		do_ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		do_pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		do_pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		do_ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		do_rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		do_rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		do_rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		do_rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		do_rrr(a, b);
	else
		return (0);
	return (1);
}

static char	*get_line(void)
{
	char		*line;
	char		c;
	int			i;
	int			ret;

	line = malloc(128);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
			break ;
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
	{
		ft_putstr("Error\n");
		return (1);
	}
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	while (1)
	{
		line = get_line();
		if (!line)
			break ;
		if (!exec_instruction(line, &stack_a, &stack_b))
		{
			free(line);
			free_stack(&stack_a);
			free_stack(&stack_b);
			ft_putstr("Error\n");
			return (1);
		}
		free(line);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
