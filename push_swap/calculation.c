/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:50:50 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:50:56 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->moves_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->pos) * -1;
		tmp_b->moves_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		moves_a;
	int		moves_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->moves_a) + nb_abs(tmp->moves_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->moves_b) + nb_abs(tmp->moves_a);
			moves_a = tmp->moves_a;
			moves_b = tmp->moves_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, moves_a, moves_b);
}
