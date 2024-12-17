/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:34 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:38 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void	print_list(t_stack *lst);
void	stack_push(t_stack **lst, t_stack *new);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
t_stack	*ft_stack(char *nptr);

#endif
