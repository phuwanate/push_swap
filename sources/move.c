#include "push_swap.h"
#include "libft.h"

void pb(t_stack *stack_a, t_stack *stack_b)
{	
	move_down(stack_b);
	stack_b->nb[0] = stack_a->nb[0];
	move_up(stack_a);
	stack_a->nb[stack_a->size - 1] = 0;
	stack_a->size--;
	stack_b->size++;
	ft_putendl_fd("pb", 1);
	//visulize(stack_a, stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{	
	move_down(stack_a);
	stack_a->nb[0] = stack_b->nb[0];
	move_up(stack_b);
	stack_b->nb[stack_b->size - 1] = 0;
	stack_b->size--;
	stack_a->size++;
	ft_putendl_fd("pa", 1);
	//visulize(stack_a, stack_b);
}

void ra(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[0];
	move_up(stack_a);
	stack_a->nb[stack_a->size - 1] = tmp;
	ft_putendl_fd("ra", 1);
	//visulize(stack_a, stack_b)
}

void rra(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[stack_a->size - 1];
	move_down(stack_a);
	stack_a->nb[0] = tmp;
	ft_putendl_fd("rra", 1);
}

void sa(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->nb[0];
	stack_a->nb[0] = stack_a->nb[1];
	stack_a->nb[1] = tmp;
	ft_putendl_fd("sa", 1);
}
