/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:48:39 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/18 14:24:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push(t_stack *stack, int val)
{
	// if (is_full(stack))
	// {
	// 	printf("ERROR");
	// 	return (1);
	// }
	stack->nb[stack->size] = val;
	stack->size++;
	return (0);
}
