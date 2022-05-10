/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:40:16 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:40:44 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_move(t_stacks *stacks, char *move)
{
	if (!ft_strcmp(move, "sa"))
		ft_swap_a(&stacks->stack_a, 0);
	else if (!ft_strcmp(move, "sb"))
		ft_swap_b(&stacks->stack_b, 0);
	else if (!ft_strcmp(move, "ss"))
		ft_ss_checker(stacks);
	else if (!ft_strcmp(move, "pa"))
		ft_push_a(&stacks->stack_a, &stacks->stack_b, 0);
	else if (!ft_strcmp(move, "pb"))
		ft_push_b(&stacks->stack_a, &stacks->stack_b, 0);
	else if (!ft_strcmp(move, "ra"))
		ft_rotate_a(&stacks->stack_a, 0);
	else if (!ft_strcmp(move, "rb"))
		ft_rotate_b(&stacks->stack_b, 0);
	else if (!ft_strcmp(move, "rr"))
		ft_rr_checker(stacks, 0);
	else if (!ft_strcmp(move, "rra"))
		ft_rra(&stacks->stack_a, 0);
	else if (!ft_strcmp(move, "rrb"))
		ft_rrb(&stacks->stack_b, 0);
	else if (!ft_strcmp(move, "rrr"))
		ft_rrr_checker(stacks);
	else
		ft_error();
}

void	ft_ss_checker(t_stacks *stacks)
{
	ft_swap_a(&stacks->stack_a, 0);
	ft_swap_b(&stacks->stack_b, 0);
}

void	ft_rr_checker(t_stacks *stacks, int c)
{
	ft_rotate_a(&stacks->stack_a, c);
	ft_rotate_b(&stacks->stack_b, c);
}

void	ft_rrr_checker(t_stacks *stacks)
{
	ft_reverse_rotate(&stacks->stack_a);
	ft_reverse_rotate(&stacks->stack_b);
}

void	ft_init_checker(t_stacks *stacks, int *numbers, int len)
{
	stacks->stack_a = ft_fill_stack_a(len, numbers);
	stacks->stack_b = NULL;
}
