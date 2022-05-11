/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:54:50 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:51:36 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrr(t_psnode **stack_a, t_psnode **stack_b, int c)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (c)
		write(1, "rrr\n", 4);
}

void	ft_add_front(t_psnode **list, t_psnode **node)
{
	(*node)->next = *list;
	*list = *node;
}

void	ft_add_back(t_psnode **list)
{
	t_psnode	*temp;

	temp = *list;
	while (temp->next)
	temp = temp->next;
	temp->next = *list;
	(*list)->next = NULL;
	*list = temp;
}

void	ft_rotate(t_psnode **list)
{
	t_psnode	*temp;

	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = *list;
	temp = (*list)->next;
	(*list)->next = NULL;
	*list = temp;
}

void	ft_reverse_rotate(t_psnode **list)
{
	t_psnode	*temp1;
	t_psnode	*temp;

	temp = *list;
	temp1 = (*list)->next;
	while (temp1->next)
	{
		temp = temp->next;
		temp1 = temp1->next;
	}
	temp1->next = *list;
	*list = temp1;
	temp->next = NULL;
}
