/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:45:44 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:50:51 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_psnode **stack_a, int c)
{
	int	node_len;

	node_len = ft_node_len(*(stack_a));
	if (node_len >= 2)
	{
		ft_rotate(stack_a);
		if (c)
			write(1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_psnode **stack_b, int c)
{
	int	node_len;

	node_len = ft_node_len(*(stack_b));
	if (node_len >= 2)
	{
		ft_rotate(stack_b);
		if (c)
			write(1, "rb\n", 3);
	}
}

void	ft_rr(t_psnode **stack_a, t_psnode **stack_b, int c)
{
	ft_rotate_a(stack_a, c);
	ft_rotate_b(stack_b, c);
	if (c)
		write(1, "rr\n", 3);
}

void	ft_rra(t_psnode **stack_a, int c)
{
	ft_reverse_rotate(stack_a);
	if (c)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_psnode **stack_b, int c)
{
	int	node_len;

	node_len = ft_node_len(*(stack_b));
	if (node_len >= 2)
	{
		ft_reverse_rotate(stack_b);
		if (c)
			write(1, "rrb\n", 4);
	}
}
