/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:22:22 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 02:59:30 by wchae            ###   ########.fr       */
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
void	a_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	size_t	num;
	t_node	*node;
	int		i;

	num = 0;
	chunk = 30;
	node = a->top;
	while (i < a->size)
	{
		if (node->index <= num)
		{
			command(a, b, "pb");
			num++;
		}
		else if (num < node->index && node->index <= num + chunk)
		{
			command(a, b, "pb");
			commnad(0, b, "rb");
			num++;
		}
		else if (num + chunk < node->index)
		{
			commnad(a, 0, "ra");
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	//a로 넘깁니다.
	//b의 가장 큰 값을 가장 효율적으로 top으로 옮깁니다.
	//b의 모든 값이 a로 넘어갈때까지 1,2를 반복
}

void	sort_big(t_stack *a, t_stack *b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}