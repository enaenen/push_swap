/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:22:22 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 15:05:35 by wchae            ###   ########.fr       */
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

double	calculate_chunk(int x)
{
	double y;
	double coefx2; 
    double coefx;
	
	coefx2 = 5.29427309e-7;
	coefx = 0.02391716881;
	y = coefx2 * (x * x) + coefx * x + 14.5;
	return (y);
}

//Chunk 식 만들기
void	a_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	int	num;
	t_node	*node;

	num = 0;
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
/*
// 3
// sort 4 일때
// 4개 중 index값이 가장 작은것을 찾아서 pb
// a size /2 위에있는지 아래있는 찾고 최소값이 위에 있으면 ra 아래 있으면 rra
//최소값을 pb -> sort 3 -> pa


//sort 5
//최악의 경우 최소값이 밑에 밑에깔린경우
//최소값 2개를 찾아서 pb
// 최악의 경우 10번
//size 가 3개 남을때까지 최소값 찾아서 ra반복, 찾으면 pb

void	b_to_a(t_stack *a, t_stack *b)
{
	//a로 넘깁니다.
	//b의 가장 큰 값을 가장 효율적으로 top으로 옮깁니다.
	//b의 모든 값이 a로 넘어갈때까지 1,2를 반복

	//모래시계의 중간값을 기준으로 => b-> size / 2 를 기준으로
	//a로 넘길 b의 최대 index 값이 위쪽인지 아래쪽인지 찾기
	// 위쪽이면 rb , 아래쪽이면 rrb해서 b의 top 으로 최대값 올리기 
	//top을 pa
	//-> 0 < b stack 동안 반복
	
}
*/
/*
void	sort_big(t_stack *a, t_stack *b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}
*/