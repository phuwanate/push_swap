/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:31:26 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/06 11:34:05 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{	
	move_down(stack_b);
	stack_b->nb[0] = stack_a->nb[0];
	move_up(stack_a);
	stack_a->nb[stack_a->size - 1] = 0;
	stack_a->size--;
	stack_b->size++;
	ft_putendl_fd("pb", 1);
}

void	sb(t_stack *stack_b)
{
	int		tmp;

	tmp = stack_b->nb[0];
	stack_b->nb[0] = stack_b->nb[1];
	stack_b->nb[1] = tmp;
	ft_putendl_fd("sb", 1);
}
