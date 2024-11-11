/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:17:21 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/10/29 12:25:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || \
		('A' <= c && c <= 'Z') || \
		('0' <= c && c <= '9'))
		return (8);
	else
		return (0);
}