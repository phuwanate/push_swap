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
#include "libft.h"
#include <stdlib.h>

void	destroy_stack(t_stack *stack)
{
	free(stack->nb);
	free(stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->size <= 0);	
}

void set_zero(int *arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void force_quit(int nb)
{
	if (nb == 0)
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}
