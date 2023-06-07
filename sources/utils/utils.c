/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:59 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 10:40:22 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	is_empty(t_stack *stack)
{
	return (stack->size <= 0);
}

void	set_zero(int *arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void	force_quit(int nb, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (nb == 0)
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	dup_check(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->nb[i] == stack_a->nb[j])
			{
				force_quit(1, stack_a, stack_b);
			}
			j++;
		}
		i++;
	}
}
