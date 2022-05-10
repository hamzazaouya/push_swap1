#include "../includes/push_swap.h"


void	ft_check_move(t_stacks *stacks, char *move)
{
	printf("*%s*\n", move);
}

void	ft_get_move(t_stacks *stacks)
{
	int control;
	char buff[2];
	char *move;
	int		i;

	buff[1] = 0;
	control = 1;
	i = 0;
	move = (char *)ft_calloc(1, sizeof(char));
	while(control)
	{
		control = read(0, buff, 1);
		if(control)
		{
			move = ft_strjoin(move, buff);
			if(*buff == '\n')
			{
				move[i] = 0;
				ft_check_move(stacks, move);
				free(move);
				move = (char *)ft_calloc(1, sizeof(char));
			}
		}
		i++;
	}
}

void ft_checker(t_stacks *stacks)
{
	ft_get_move(stacks);
}

void ft_init_checker(t_stacks *stacks, int *numbers, int argc)
{
	stacks->stack_a = ft_fill_stack_a(argc - 1, numbers);
	stacks->stack_b = NULL;
}

int main(int argc, char **argv)
{
	t_stacks stacks;
	int			*numbers;

	ft_check_input(argc, argv);
	ft_init_checker(&stacks,numbers, argc);
	ft_checker(&stacks);
}