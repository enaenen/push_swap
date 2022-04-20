/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:06:50 by wchae             #+#    #+#             */
/*   Updated: 2022/04/20 23:24:03 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_back(t_stack *stack, t_stack_node *new)
{
	if (stack->count == 0)
	{
		stack->head = new;
		stack->tail = stack->head;
	}
	else
	{
		stack->tail->next = new;
		new->prev = stack->tail; 
		stack->tail = new;
	}
	stack->count++;
}

t_stack_node	*new_node(int	data)
{
	t_stack_node	*node;
	node = (t_stack_node*) malloc(sizeof(t_stack_node));
	if (!node)
		erorr_handle();
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	init_stack_data(char *str, t_stack *stack)
{
	long long	data;
	t_stack_node	*node;

	if (ft_strlen(str) > 11)
		error_handle();
	data = ft_atoi(str);
	if (2147483647 < data || data < -2147483648)
		error_handle();
	node = stack->head;
	while (node)
	{
		if (node->data == (int)data)
			error_handle();
		node = node->next;
	}
	stack_add_back(stack, new_node(data));
}

void	init_stack(t_ps *stack)
{
	ft_bzero(stack, sizeof(t_ps));
}

t_stack_node	*new_stack_node(int data)
{
	t_stack_node	*new;
	
	new = (t_stack_node*)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}