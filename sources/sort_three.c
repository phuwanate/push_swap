#include "push_swap.h"

void sort_three(t_stack *stack_a)
{
	if((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] < stack_a->nb[2])
		&& (stack_a->nb[0] < stack_a->nb[2]))
		sa(stack_a);
	else if((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
			&& (stack_a->nb[0] > stack_a->nb[2]))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] < stack_a->nb[2])
			&& (stack_a->nb[0] > stack_a->nb[2]))
		ra(stack_a);
	else if((stack_a->nb[0] < stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
			&& (stack_a->nb[0] < stack_a->nb[2]))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if((stack_a->nb[0] < stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
			&& (stack_a->nb[0] > stack_a->nb[2]))
		rra(stack_a);
	else if((stack_a->nb[0] > stack_a->nb[1]))
		sa(stack_a);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
} 
