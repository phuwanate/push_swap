/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:29:27 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/06 11:34:50 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if ((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] < stack_a->nb[2])
		&& (stack_a->nb[0] < stack_a->nb[2]))
		sa(stack_a);
	if ((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
		&& (stack_a->nb[0] > stack_a->nb[2]))
	{
		sa(stack_a);
		rra(stack_a);
	}
	if ((stack_a->nb[0] > stack_a->nb[1]) && (stack_a->nb[1] < stack_a->nb[2])
		&& (stack_a->nb[0] > stack_a->nb[2]))
		ra(stack_a);
	if ((stack_a->nb[0] < stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
		&& (stack_a->nb[0] < stack_a->nb[2]))
	{
		sa(stack_a);
		ra(stack_a);
	}
	if ((stack_a->nb[0] < stack_a->nb[1]) && (stack_a->nb[1] > stack_a->nb[2])
		&& (stack_a->nb[0] > stack_a->nb[2]))
		rra(stack_a);
	else if ((stack_a->nb[0] > stack_a->nb[1]))
		sa(stack_a);
}
