#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				*nb;
	int				capacity;
	int				size;
}	t_stack;

t_stack	*make_stack(int capacity)
{
	t_stack	*stack;


	stack = malloc(sizeof(t_stack));
	if(!stack)
		return NULL;
	stack->nb = malloc(sizeof(int) * capacity);
	if(!(stack->nb))
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;

	return(stack);
}

void destroy_stack(t_stack *stack)
{
	free(stack->nb);
	free(stack);
}

int is_full(t_stack *stack)
{
	return (stack->capacity == stack->size);
}

int is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int push(t_stack *stack, int val)
{
	if(is_full(stack))
		return (1);
	stack->nb[stack->size] = val;
	stack->size++;

	return (0);
}


int main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int i = 1;
	int top;

	stack_a = make_stack(ac - 1);
	stack_b = make_stack(ac - 1);
	if(!stack_a)
	{
		exit (1);
	}
	while(i < ac)
	{
		push(stack_a, atoi(av[i]));
		i++;
	}
	i = 0;
	while(ac > 1)
	{
		printf("%d \n", stack_a->nb[i++]);
		ac--;
	}
	printf("stack A\n");
	printf("%d\n", stack_b->nb[0]);
	printf("stack B\n");
	destroy_stack(stack_a);
}

