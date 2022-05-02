/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:02:36 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 22:34:08 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*popped;

	if (!stack || stack->size < 1)
		return (NULL);
	popped = stack->top;
	if (1 < stack->size)
		stack->top = popped->next;
	else
		stack->top = NULL;
	stack->size--;
	return (popped);
}

int	push(t_stack *stack, t_node element)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_handle(ALLOC_ERROR);
	*new = element;
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

int	reverse_push(t_stack *stack, t_node element)
{
	t_node	*new;
	t_node	*old;

	if (!stack)
		return (FALSE);
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_handle(ALLOC_ERROR);
	*new = element;
	new->next = NULL;
	if (stack->size == 0)
	{
		stack->bottom = new;
		stack->top = new;
	}
	else
	{
		old = stack->bottom;
		old->next = new;
		new->next = NULL;
		stack->bottom = new;
		stack->top = old;
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
	t_node	*node;
	int		size;
	int		i;

	i = 0;
	size = stack->size;
	while (i < size)
	{
		node = pop(stack);
		free(node);
		i++;
	}
}
