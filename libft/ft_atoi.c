/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:16:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/08 16:13:10 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void is_valid(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if(!(ft_isdigit(s[i])))
			force_quit(1);
		i++;
	}
}

static void check_result(int num1, int num2, int sign)
{
    if(((sign > 0) && (num1 > 2147483647 - num2)) ||
		((sign < 0) && (num1 > 2147483648 - num2)))
	{
        force_quit(1);
    }
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	is_valid((char *)str);
	while (*str >= '0' && *str <= '9')
	{
		check_result(result * 10, (*str - '0'), sign);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
