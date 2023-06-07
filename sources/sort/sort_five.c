/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:38:09 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 10:37:02 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack_a, int nb, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (stack_a->nb[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

void	to_top(int index, t_stack *stack_a, t_stack *stack_b)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3 && stack_a->size != 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = find_index(stack_a, 0, stack_a->size);
	to_top(index, stack_a, stack_b);
	index = find_index(stack_a, 1, stack_a->size);
	to_top(index, stack_a, stack_b);
	sort_three(stack_a);
	if (stack_b->nb[0] < stack_b->nb[1])
		sb(stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
