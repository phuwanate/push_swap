/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:48:39 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 15:06:15 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	push(t_stack *stack_a, int val)
{
	stack_a->nb[stack_a->size] = val;
	stack_a->size++;
	return (0);
}
