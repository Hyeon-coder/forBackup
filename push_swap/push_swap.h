/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:37:42 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/27 19:39:08 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

t_stack	*input_parse(int ac, char **av);
int		ft_isvalid_input(char **av);
int		check_double(t_stack *a);
void	exit_error(int i, t_stack *a, t_stack *b);
int		ft_atoi(const char *str);
void	stack_push(t_stack **lst, t_stack *new);
t_stack	*stack_pop(t_stack **lst);
int		stack_peek(t_stack *lst);
void	free_stack(t_stack *stack);
t_stack	*ft_lstnew(int num);
t_stack	*input_tmp_stack(int ac, char **av);
int		ft_lstsize(t_stack *lst);
void	ps_push(t_stack **lst, t_stack **dst);
void	pa(t_stack **lst, t_stack **dst);
void	pb(t_stack **lst, t_stack **dst);
void	ps_swap(t_stack **lst);
void	sa(t_stack **lst, int flag);
void	sb(t_stack **lst, int flag);
void	ss(t_stack **lst, t_stack **lst2);
void	ps_rotate(t_stack **lst);
void	ra(t_stack **lst, int flag);
void	rb(t_stack **lst, int flag);
void	rr(t_stack **lst, t_stack **lst2);
void	ps_reverse(t_stack **lst);
void	rra(t_stack **lst, int flag);
void	rrb(t_stack **lst, int flag);
void	rrr(t_stack **lst, t_stack **lst2);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		calculate_pivot(t_stack *a);
void	sort_array(int *arr, int size);
int		*stack_to_array(t_stack *a, int size);
void	sort_three(t_stack **a);
void	quicksort_stack(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void 	stack_append(t_stack **stack, t_stack *new_node);

#endif
