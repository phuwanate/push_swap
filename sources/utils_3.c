/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:34:33 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/06 14:46:32 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	get_capa(char *s)
{
	char	**arg_split;
	int		i;

	arg_split = ft_split(s, ' ');
	if (!arg_split)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	i = 0;
	while (arg_split[i])
		i++;
	free_split (arg_split);
	return (i);
}
