/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:46 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 16:05:24 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
// 3
// sort 4 일때
// 4개 중 index값이 가장 작은것을 찾아서 pb
// a size /2 위에있는지 아래있는 찾고 최소값이 위에 있으면 ra 아래 있으면 rra
//최소값을 pb -> sort 3 -> pa
*/
// void	sort_4(t_stack *a, t_stack *b)
// {
	
// }



//sort 5
//최악의 경우 최소값이 밑에 밑에깔린경우
//최소값 2개를 찾아서 pb
// 최악의 경우 10번
//size 가 3개 남을때까지 최소값 찾아서 ra반복, 찾으면 pb

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
	node = stack->top;
	int	min;
	int	i;

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
	int min_index;

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
	int i;

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