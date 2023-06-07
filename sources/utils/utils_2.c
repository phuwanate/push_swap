/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:39:04 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 15:07:26 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	check_flow(int num1, int num2, int sign)
{
	if (((sign > 0) && (num1 > 2147483647 / 10))
		|| ((sign < 0) && (num1 > 2147483648 / 10)))
		return (1);
	num1 *= 10;
	if (((sign > 0) && (num1 > 2147483647 - num2))
		|| ((sign < 0) && (num1 > 2147483648 - num2)))
		return (1);
	return (0);
}

static void	space_check(char **str)
{
	while (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

static int	sign_check(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

int	re_atoi(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	sign;
	int	result;
	int	status;

	result = 0;
	space_check(&str);
	sign = sign_check(&str);
	if (*str == '\0')
		force_quit(1, stack_a, stack_b);
	status = is_valid(str);
	if (status == 1)
		force_quit(1, stack_a, stack_b);
	while (*str >= '0' && *str <= '9')
	{
		status = check_flow(result, (*str - '0'), sign);
		if (status == 1)
			force_quit(1, stack_a, stack_b);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
