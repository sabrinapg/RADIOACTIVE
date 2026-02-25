/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:53:52 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 02:56:48 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				moves_a;
	int				moves_b;
	struct s_stack	*next;
}	t_stack;

/* Stack */
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
int			get_stack_size(t_stack *stack);

/* Utils */
void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
int			ft_strcmp(const char *s1, const char *s2);

/* Input */
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/* Init */
t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int stack_size);

/* Operations */
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/* Sort */
int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		do_move(t_stack **a, t_stack **b, int moves_a, int moves_b);

#endif
