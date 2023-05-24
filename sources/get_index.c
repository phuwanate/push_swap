#include "push_swap.h"

static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void dup(int *s_a, int *s_b, unsigned int size)
{
	unsigned int i;

	i = 0;
	while(i < size)
	{
		s_b[i] = s_a[i];
		i++;
	}
}

static void init_index(int *s_a, int *s_b, int size)
{
	int		i;
	int		j;

	i = 0;
	while (s_a[i])
	{
		j = 0;
		while (s_b[j])
		{
			if (s_a[i] == s_b[j])
			{
				s_a[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	set_zero(s_b, size);
}

void	get_index(t_stack *s_a, t_stack *s_b)
{
	int					i;
	int					status;
	int					ok;

	dup(s_a->nb, s_b->nb, s_a->size);
	status = 1;
	ok = 1;
	while (status == 1)
	{
		status = 0 ;
		i = 0;
		while (i < s_a->size - 1)
		{
			if (s_b->nb[i] > s_b->nb[i + 1])
			{
				swap(&s_b->nb[i], &s_b->nb[i + 1]);
				status = 1;
				ok = 0;
			}
			i++;
		}
	}
	if (ok == 1)
		force_quit(0, s_a, s_b);
	init_index(s_a->nb, s_b->nb, s_a->size);
}
