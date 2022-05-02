/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:46 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 18:31:39 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_2_min(t_stack *a, int cnt, int *min, int *second_min)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->top;
	*min = 2147483647;
	while (i++ < cnt)
	{
		if (node->index < *min)
		{
			*second_min = *min;
			*min = node->index;
		}
		else if (node->index < *second_min)
			*second_min = node->index;
		node = node->next;
	}
}

static int	find_min_index(t_stack *stack, int *min_index)
{
	t_node	*node;
	int		min;
	int		i;

	node = stack->top;
	*min_index = 1;
	min = 2147483647;
	i = stack->size;
	while (0 < i)
	{
		if (node->index <= min)
		{
			min = node->index;
			*min_index += 1;
		}
		node = node->next;
		i--;
	}
	return (min);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min;
	int	min_index;

	min = find_min_index(a, &min_index);
	while (3 < a->size)
	{
		if (a->top->index == min)
			command(a, b, "pb");
		else
			command(a, 0, "ra");
	}
	sort_3(a);
	command(a, b, "pa");
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min[2];
	int	i;

	find_2_min(a, 5, &min[0], &min[1]);
	i = 0;
	while (i < 5)
	{
		if (a->top->index == min[0] || a->top->index == min[1])
			command(a, b, "pb");
		else
			command(a, 0, "ra");
		i++;
	}
	if (b->top->index == min[0])
		command(0, b, "rb");
	sort_3(a);
	command(a, b, "pa");
	command(a, b, "pa");
}
