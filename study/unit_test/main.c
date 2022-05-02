/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:17 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 18:34:09 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	error_handle(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

int	is_ascending(t_stack *stack, int cnt)
{
	int		i;
	t_node	*tmp;

	tmp = stack->top;
	i = 1;
	while (i < cnt && tmp->next)
	{
		if (tmp->next->data < tmp->data)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

t_node	*get_min_value_node(t_stack *stack)
{
	int		min;
	int		i;
	t_node	*node;
	t_node	*ret;

	min = 2147483647;
	node = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (node->data <= min && !node->index)
		{
			min = node->data;
			ret = node;
		}
		node = node->next;
		i++;
	}
	return (ret);
}

void	indexing_stack(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->top;
	i = 1;
	while (i <= stack->size)
	{
		node = get_min_value_node(stack);
		node->index = i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error_handle(-1);
	a = parse_argv(argc, argv);
	indexing_stack(a);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		error_handle(ALLOC_ERROR);
	if (a->size == 5)
		sort_5(a, b);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 3)
		sort_3(a);
	else if (5 < a->size)
		sort_big(a, b);
	// system("leaks push_swap");
}
