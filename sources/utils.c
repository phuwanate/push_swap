/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:59 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/18 14:29:25 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	destroy_stack(t_stack *stack)
{
	free(stack->nb);
	free(stack);
}

// int	is_full(t_stack *stack)
// {
// 	return (stack->capacity == stack->size);
// }

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
