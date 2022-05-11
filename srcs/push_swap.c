/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:44:44 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:49:46 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(int argc, int *numbers, t_pushswap_data *psdata)
{
	psdata->argc = argc;
	psdata->stack_a = ft_fill_stack_a(argc - 1, numbers);
	psdata->stack_b = NULL;
	psdata->len_a = argc - 1;
	psdata->len_b = 0;
	psdata->maxs_len = 2;
	psdata->maxs = (t_maxs *)malloc(sizeof(t_maxs) * psdata->maxs_len);
	ft_prepare_stack_a(psdata->stack_a, numbers);
}

int	main(int argc, char **argv)
{
	t_pushswap_data	psdata;
	int				*numbers;

	numbers = ft_check_input(argc, argv);
	ft_init(argc, numbers, &psdata);
	ft_push_atb(&psdata);
	ft_push_bta(&psdata);
}
