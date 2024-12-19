/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:34 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/19 15:34:32 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	char			*data;
	struct s_stack	*next;
}	t_stack;

void	print_list(t_stack *lst);
void	stack_push(t_stack **lst, t_stack *new);
void	stack_pop(t_stack *lst);
void	ft_switch();
void	ft_move(t_stack *a, t_stack *b);
void	ft_rotate();
void	ft_revers_rotate();
int	ft_isdigit(int c);

t_stack	*ft_stack(char *nptr);

#endif
