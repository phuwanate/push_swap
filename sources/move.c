#include "push_swap.h"

void pb(t_stack *stack_a, t_stack *stack_b)
{	
	stack_b->nb[stack_a->size - 1] = stack_a->nb[0];
	move_up(stack_a);
	stack_a->nb[stack_a->size - 1] = 0;
	stack_a->size--;
	stack_b->size++;
	visulize(stack_a, stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{	
	stack_a->nb[stack_b->size - 1] = stack_b->nb[0];
	move_up(stack_b);
	stack_b->nb[stack_b->size - 1] = 0;
	stack_b->size--;
	stack_a->size++;
	visulize(stack_a, stack_b);
}
