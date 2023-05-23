#include "push_swap.h"

void move_up(t_stack *stack)
{
	int		i;

	i = 0;
	while(i < stack->size - 1)
	{
		stack->nb[i] = stack->nb[i + 1];
		i++;
	}
}
