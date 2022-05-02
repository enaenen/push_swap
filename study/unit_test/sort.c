/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:22:22 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 18:28:23 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_chunk(int x)
{
	double	y;
	double	coefx2;
	double	coefx;

	coefx2 = 5.29427309e-7;
	coefx = 0.02391716881;
	y = coefx2 * (x * x) + coefx * x + 14.5;
	return (y);
}

void	a_to_b(t_stack *a, t_stack *b)
{
	int		chunk;
	int		num;
	t_node	*node;

	num = 1;
	chunk = calculate_chunk(a->size);
	while (0 < a->size)
	{
		node = a->top;
		if (node->index <= num)
		{
			command(a, b, "pb");
			num++;
		}
		else if (num < node->index && node->index <= num + chunk)
		{
			command(a, b, "pb");
			command(0, b, "rb");
			num++;
		}
		else if (num + chunk < node->index)
		{
			command(a, 0, "ra");
		}
	}
}

int	find_location(t_stack *stack, int max)
{
	t_node	*node;
	int		location;

	location = 0;
	node = stack->top;
	while (node->index != max)
	{
		node = node->next;
		location++;
	}
	return (max / 2 - location);
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	location;

	while (0 < b->size)
	{
		max = b->size;
		location = find_location(b, max);
		if (b->top->index == max)
			command(a, b, "pa");
		else if (0 <= location)
			command(0, b, "rb");
		else if (location < 0)
			command(0, b, "rrb");
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}
