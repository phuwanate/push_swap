/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:23:20 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/06 11:48:30 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{	
	move_down(stack_a);
	stack_a->nb[0] = stack_b->nb[0];
	move_up(stack_b);
	stack_b->nb[stack_b->size - 1] = 0;
	stack_b->size--;
	stack_a->size++;
	ft_putendl_fd("pa", 1);
}

void	ra(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[0];
	move_up(stack_a);
	stack_a->nb[stack_a->size - 1] = tmp;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[stack_a->size - 1];
	move_down(stack_a);
	stack_a->nb[0] = tmp;
	ft_putendl_fd("rra", 1);
}

void	sa(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[0];
	stack_a->nb[0] = stack_a->nb[1];
	stack_a->nb[1] = tmp;
	ft_putendl_fd("sa", 1);
}
