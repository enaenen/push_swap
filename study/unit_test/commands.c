/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:28:57 by wchae             #+#    #+#             */
/*   Updated: 2022/05/01 17:42:31 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	swap_top(t_stack *stack)
{
	int n;

	if (!stack || stack->size < 2)
		return (FALSE);
	n = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = n;
	return(TRUE);
}

int	trade_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (!from || !to)
		return (FALSE);
	if (from->size < 1)
		return (FALSE);
	tmp = pop(from);
	push(to, *tmp);
	free(tmp);
	return (TRUE);
}

int	rotate(t_stack *stack)
{
	t_node *tmp;
	
	if (!stack || stack->size < 2)
		return (FALSE);
	if (stack->size < 3)
		return (swap_top(stack));
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
	stack->bottom->next = NULL;
	return (TRUE);
}

int reverse_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*prev_bottom;
	int i;

	if (!stack || stack->size < 2)
		return (FALSE);
	if (stack->size < 3)
		return (swap_top(stack));
	prev_bottom = stack->top;
	i = 0;
	while (++i < stack->size - 1)
		prev_bottom = prev_bottom->next;
	tmp = stack->bottom;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->bottom = prev_bottom;
	stack->bottom->next = NULL;
	return (TRUE);
}

void	rotate_both_command(t_stack *a, t_stack *b, char *str)
{
	if (!a || !b)
		return ;
	if (a->size < 2 || b->size < 2)
		return ;
	else if (!ft_strcmp(str, "ss") && swap_top(a) && swap_top(b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "rr") &&rotate(a) && rotate(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rrr") && reverse_rotate(a) && reverse_rotate(b))
		write(1, "rrr\n", 4);
}

void	command(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "pa") && trade_push(b, a))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && trade_push(a, b))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "sa") && swap_top(a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && swap_top(b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ra") && rotate(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && rotate(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rra") && reverse_rotate(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && reverse_rotate(b))
		write(1, "rrb\n", 4);
} 