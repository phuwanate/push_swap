#include <stdio.h>
#include "push_swap.h"

static int get_bits(int max_num)
{
	size_t	count;

	count = 0;
	while(max_num != 0)
	{
		count++;
		max_num >>= 1;
	}
	return (count);
}


void radix(t_stack *stack_a, t_stack *stack_b)
{
	int j;
	int max_bits;
	int max_num;

	max_num = stack_a->size - 1;
	max_bits = get_bits(max_num);

	j = 0;
	while(j <= max_bits)
	{
	 	while(stack_a->size)
	 		pb(stack_a, stack_b);
 		j++;
 	}
	while(stack_b->size)
 		pa(stack_a, stack_b);
}
