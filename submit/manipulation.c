/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:28:57 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 18:32:11 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_top(t_stack *stack)
{
	int	n;
	int	index;

	if (!stack || stack->size < 2)
		return (FALSE);
	n = stack->top->data;
	index = stack->top->index;
	stack->top->data = stack->top->next->data;
	stack->top->index = stack->top->next->index;
	stack->top->next->data = n;
	stack->top->next->index = index;
	return (TRUE);
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
	t_node	*tmp;

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

int	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*prev_bottom;
	int		i;

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
