/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:18:36 by plertsir          #+#    #+#             */
/*   Updated: 2023/05/18 14:49:32 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				*nb;
	int				capacity;
	int				size;
	int				max;
}	t_stack;

int		push(t_stack *stack, int val);
void	destroy_stack(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	free_split(char **arg_split);
void	free_stack(t_stack *stack_a, t_stack *stack_b);
void	get_index(int *s_a, int *s_b, unsigned int size);
void	set_zero(int *arr, unsigned int size);
void	force_quit(int nb);
void 	radix(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void 	move_up(t_stack *stack);
void	visulize(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);

#endif
