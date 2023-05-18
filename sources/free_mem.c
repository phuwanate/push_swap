/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:28 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/18 14:49:59 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_split(char **arg_split)
{
	size_t	i;

	i = 0;
	while (arg_split[i])
	{
		free(arg_split[i]);
		i++;
	}
	free(arg_split);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->nb);
	free(stack_a);
	free(stack_b->nb);
	free(stack_b);
}
