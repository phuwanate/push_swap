/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:30:46 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/06 18:03:53 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	move_up(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size - 1)
	{
		stack->nb[i] = stack->nb[i + 1];
		i++;
	}
}

void	move_down(t_stack *stack)
{
	int		i;

	i = stack->size;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		i--;
	}
	stack->nb[0] = 0;
}
