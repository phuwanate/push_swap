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
	int i;
	int max_bits;
	int max_num;

	max_num = stack_a->size - 1;
	max_bits = get_bits(max_num);
	j = 0;
	while(j < max_bits)
	{
		i = 0;
	 	while(i <= max_num)
		{
	 		if(stack_a->size > 3)
			{
				if((stack_a->nb[0]) & (1 << j))	
					ra(stack_a);
				else
					pb(stack_a, stack_b);
			}
			//else
			//	sort_three(stack_a);
			i++;
		}
		while(stack_b->size)
 			pa(stack_a, stack_b);
		j++;
	}
}
