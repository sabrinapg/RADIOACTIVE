/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:52:26 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:55:25 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate_both(t_stack **a, t_stack **b, 
					int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		(*moves_a)++;
		(*moves_b)++;
		do_rrr(a, b);
	}
}

static void	do_rotate_both(t_stack **a, t_stack **b,
							int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		(*moves_a)--;
		(*moves_b)--;
		do_rr(a, b);
	}
}

static void	do_rotate_a(t_stack **a, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			do_ra(a);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			do_rra(a);
			(*moves)++;
		}
	}
}

static void	do_rotate_b(t_stack **b, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			do_rb(b);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			do_rrb(b);
			(*moves)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int moves_a, int moves_b)
{
	if (moves_a < 0 && moves_b < 0)
		do_rev_rotate_both(a, b, &moves_a, &moves_b);
	else if (moves_a > 0 && moves_b > 0)
		do_rotate_both(a, b, &moves_a, &moves_b);
	do_rotate_a(a, &moves_a);
	do_rotate_b(b, &moves_b);
	do_pa(a, b);
}
