/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:25:32 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:39:59 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_buff(t_stacks *stacks, char *move, char *buff, int *i)
{	
	if (*buff == '\n')
	{
		move[*i] = 0;
		*i = -1;
		ft_check_move(stacks, move);
	}
}

void	ft_get_move(t_stacks *stacks)
{
	int		control;
	char	*buff;
	char	*move;
	int		i;

	control = 1;
	i = 0;
	buff = (char *)ft_calloc(2, sizeof(char));
	move = (char *)ft_calloc(1, sizeof(char));
	while (control)
	{
		control = read(0, buff, 1);
		move = ft_strjoin(move, buff);
		if (control)
			ft_check_buff(stacks, move, buff, &i);
		if (*buff == '\n')
		{
			free(move);
			move = (char *)ft_calloc(1, sizeof(char));
		}
		i++;
	}
	free(move);
	free(buff);
}

void	ft_ckeck_sort(t_stacks *stacks)
{
	t_psnode	*temp;
	int			len_b;

	temp = stacks->stack_a;
	while (temp)
	{
		if (temp->next && (temp->num > temp->next->num))
		{
			write(1, "KO\n", 3);
			return ;
		}
		temp = temp->next;
	}
	len_b = ft_node_len(stacks->stack_b);
	if (len_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	ft_checker(t_stacks *stacks)
{
	ft_get_move(stacks);
	ft_ckeck_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*numbers;

	numbers = ft_check_input(argc, argv);
	ft_init_checker(&stacks, numbers, argc - 1);
	ft_checker(&stacks);
}
