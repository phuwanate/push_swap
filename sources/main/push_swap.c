/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:17:32 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 15:06:23 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static t_stack	*make_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nb = malloc(sizeof(int) * capacity);
	if (!(stack->nb))
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

static int	get_val(t_stack *stack_a, t_stack *stack_b, char *s)
{
	char	**arg_split;
	int		i;

	arg_split = ft_split(s, ' ');
	if (!arg_split)
		force_quit(1, stack_a, stack_b);
	i = 0;
	while (arg_split[i])
	{
		push(stack_a, re_atoi(arg_split[i], stack_a, stack_b));
		i++;
	}
	free_split (arg_split);
	return (0);
}

static void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->nb[0] > stack_a->nb[1])
			sa(stack_a);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		size;

	if (ac < 2)
		exit(0);
	i = 1;
	size = 0;
	while (i < ac)
		size += get_capa(av[i++]);
	stack_a = make_stack(size);
	stack_b = make_stack(size);
	if (!stack_a || !stack_b)
		force_quit(1, stack_a, stack_b);
	i = 1;
	while (i < ac)
		get_val(stack_a, stack_b, av[i++]);
	dup_check(stack_a, stack_b);
	get_index(stack_a, stack_b);
	check_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
