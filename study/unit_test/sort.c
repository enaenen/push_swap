/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:22:22 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 02:40:18 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack	*a)
{
	if (a->top->next->data < a->top->data)
		command(a, 0, "sa");
	else
		return ;
	return ;
}

void	sort_3(t_stack	*a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->data;
	mid = a->top->next->data;
	bot = a->top->next->next->data;
	if (bot < mid && mid < top && bot < top)
	{
		command(a, 0, "sa");
		command(a, 0, "rra");
	}
	else if (mid < top && mid < bot && bot < top)
		command(a, 0, "ra");
	else if (top < mid && bot < mid && top < bot)
	{
		command(a, 0, "sa");
		command(a, 0, "ra");
	}
	else if (mid < top && top < bot && mid < bot)
		command(a, 0, "sa");
	else if (bot < mid && top < mid && bot < top)
		command(a, 0, "rra");
}

void	sort_big(t_stack *a, t_stack *b)
{
	double	chunk;
	size_t	num;
	t_node	*node;
	int		i;

	num = a->size;
	chunk = 0.000000053;
	num = chunk * num * num + 0.03 * num + 14.5;
	i = 0;
	node = a->top;
	// while (i < a->size)
	// {
	// 	if (node->index <= num)

	// }
}