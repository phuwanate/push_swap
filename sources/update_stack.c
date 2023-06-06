#include "push_swap.h"

void move_up(t_stack *stack)
{
	int		i;

	i = 0;
	while(i < stack->size)
	{
		stack->nb[i] = stack->nb[i + 1];
		i++;
	}
}

void move_down(t_stack *stack)
{
	int		i;

	i = stack->size;
	while(i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[i] = 0;
}
