/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:23:08 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 15:09:59 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits(int max_num)
{
	int	count;

	count = 0;
	while (max_num != 0)
	{
		count++;
		max_num >>= 1;
	}
	return (count);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	i;
	int	max_bits;
	int	max_num;

	max_num = stack_a->size - 1;
	max_bits = get_bits(max_num);
	j = 0;
	while (j < max_bits)
	{
		i = 0;
		while (i <= max_num)
		{
			if ((stack_a->nb[0]) & (1 << j))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (stack_b->size)
			pa(stack_a, stack_b);
		j++;
	}
}
