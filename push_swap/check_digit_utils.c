/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:25:22 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/10 14:01:20 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == ' ' || (9 <= av[i][j] && av[i][j] <= 13))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isvalid_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!('0' <= av[i][j] && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}