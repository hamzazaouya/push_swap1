/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:11:07 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/10 16:42:15 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h> 
# include "../libft/libft.h"

typedef struct ps_node
{
	int				num;
	int				index;
	struct ps_node	*next;
}	t_psnode;

typedef struct maxs
{
	int	num;
	int	pos;
	int	side;
}	t_maxs;

typedef struct stacks
{
	t_psnode	*stack_a;
	t_psnode	*stack_b;
}	t_stacks;

typedef struct push_swap
{
	int			argc;
	int			len_a;
	int			len_b;
	int			facture;
	int			maxs_len;
	t_maxs		*maxs;
	t_psnode	*stack_a;
	t_psnode	*stack_b;
}	t_pushswap_data;

t_psnode	*ft_fill_stack_a(int argc, int *numbers);
int			ft_atoi(const char *str);
void		ft_swap_a(t_psnode **stack_a, int c);
void		ft_swap_b(t_psnode **stack_b, int c);
void		ft_swap_ss(t_pushswap_data *psdata, int c);
void		ft_push_b(t_psnode **stack_a, t_psnode **stack_b, int c);
t_psnode	*ft_create_node(void);
void		ft_add_front(t_psnode **list, t_psnode **node);
void		ft_add_back(t_psnode **list);
int			ft_node_len(t_psnode *node);
void		ft_push_a(t_psnode **stack_a, t_psnode **stack_b, int c);
void		ft_push_b(t_psnode **stack_a, t_psnode **stack_b, int c);
void		ft_rotate(t_psnode **list);
void		ft_rotate_a(t_psnode **stack_a, int c);
void		ft_rotate_b(t_psnode **stack_b, int c);
void		ft_rra(t_psnode **stack_a, int c);
void		ft_reverse_rotate(t_psnode **list);
void		ft_rrb(t_psnode **stack_b, int c);
void		ft_rrr(t_psnode **stack_a, t_psnode **stack_b, int c);
void		ft_push_atb(t_pushswap_data *psdata);
void		ft_push_bta(t_pushswap_data *psdata);
void		ft_getpos(t_pushswap_data *psdata);
int			ft_strcmp(char *str1, char *str2);
void		ft_rr(t_psnode **stack_a, t_psnode **stack_b, int c);
void		ft_get_maxes(t_pushswap_data *psdata);
void		ft_prepare_stack_a(t_psnode *stack_a, int *numbers);
int			*ft_check_input(int argc, char **argv);
void		ft_error(void);
void		ft_ss_checker(t_stacks *stacks);
void		ft_rr_checker(t_stacks *stacks, int c);
void		ft_rrr_checker(t_stacks *stacks);
void		ft_init_checker(t_stacks *stacks, int *numbers, int argc);
void		ft_check_move(t_stacks *stacks, char *move);
#endif
