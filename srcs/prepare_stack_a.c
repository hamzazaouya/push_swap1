/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:45:35 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:46:04 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_arr(int *arr, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
			continue ;
		}
		i++;
	}
}

int	ft_serch_arr(int *arr, int num)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
}

void	ft_prepare_stack_a(t_psnode *stack_a, int *numbers)
{
	ft_sort_arr(numbers, ft_node_len(stack_a));
	while (stack_a)
	{
		stack_a->index = ft_serch_arr(numbers, stack_a->num);
		stack_a = stack_a->next;
	}
	free(numbers);
}
