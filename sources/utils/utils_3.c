/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:34:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/07 14:58:13 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static void	check_empty(char *s)
{
	int	i;
	int	status;

	if (*s == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	status = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			status = 1;
		i++;
	}
	if (status == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	get_capa(char *s)
{
	char	**arg_split;
	int		i;

	check_empty(s);
	arg_split = ft_split(s, ' ');
	if (!arg_split)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (arg_split[i])
		i++;
	free_split (arg_split);
	return (i);
}
