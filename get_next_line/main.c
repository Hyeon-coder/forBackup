/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:01:23 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/23 13:34:30 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>   // open()
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*str;
	fd = open("./test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
