/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:16:13 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/04 01:01:52 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnt_num(int n)
{
	int	cnt;

	cnt = 0;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*rst;
	int		len;

	if (n < 0)
		return (0);
	len = cnt_num(n);
	rst = (char *)malloc(len * sizeof(char) + 1);
	while (n != 0)
	{
		rst[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (rst);
}
