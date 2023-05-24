/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:17:32 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/18 17:06:33 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static t_stack	*make_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return(NULL);
	stack->nb = malloc(sizeof(int) * capacity);
	if (!(stack->nb))
	{
		free(stack);
		return(NULL);
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

void visulize(t_stack *stack_a, t_stack *stack_b)
{
	int i = 0;
	printf("size of stack A %d \n", stack_a->size);
	printf("size of stack B %d \n", stack_b->size);
	printf("-     -\n");
	while(i < stack_a->max)
	{
		if(is_empty(stack_a))
			printf("      ");
		else
			printf("%d     ", stack_a->nb[i]);
		if(is_empty(stack_b))
			printf("      \n");
		else
			printf("%d\n", stack_b->nb[i]);
		i++;
	}
	printf("-     -\n");
	printf("A     B\n");
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if(ac < 2)
		exit(1);
	stack_a = make_stack(ac - 1);
	stack_b = make_stack(ac - 1);
	if(!stack_a || !stack_b)
		force_quit(1, stack_a, stack_b);
	i = 1;
	while (i < ac)
		get_val(stack_a, stack_b, av[i++]);
	dup_check(stack_a, stack_b);
	get_index(stack_a, stack_b);
	visulize(stack_a, stack_b);
	radix(stack_a, stack_b);
	printf("----------------------");
	printf("\nAfter sorted\n\n");
	visulize(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
