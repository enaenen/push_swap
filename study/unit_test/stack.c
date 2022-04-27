/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:02:36 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 22:25:43 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*popped;
	
	if (!stack)
		return (NULL);

	popped = stack->top;
	if (1 < stack->size)
		stack->top = popped->next;
	else
		stack->top = NULL;
	stack->size--;
	return (popped);
}

int		push(t_stack *stack, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_handle(ALLOC_ERROR);
	new->data = data;
	new->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->top;
		stack->top = new;
	}
	stack->size++;
	return (TRUE);
}

t_node	*peek(t_stack *stack)
{
	return (stack->top);
}

void	print_stack(t_stack *stack)
{
	t_node *node;
	node = peek(stack);
	while (node)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}