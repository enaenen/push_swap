/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:59:17 by wchae             #+#    #+#             */
/*   Updated: 2022/04/25 15:05:36 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->b_size < 1)
		return ;
	node = ps->b_top;
	if (1 < ps->b_size)
	{
		ps->b_top = ps->b_top->next;
		ps->b_top->prev = NULL;
	}
	if (ps->a_size == 0)
	{
		ps->a_top = node;
		ps->a_bottom = node;
		node->next = NULL;
	}
	else
	{
		node->next = ps->a_top;
		ps->a_top->prev = node;
		ps->a_top = node;
	}
	ps->a_size++;
	ps->b_size--;
	write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->a_size < 1)
		return ;
	node = ps->a_top;
	if (1 < ps->a_size)
	{
		ps->a_top = ps->a_top->next;
		ps->a_top->prev = NULL;
	}
	if (ps->b_size == 0)
	{
		ps->b_top = node;
		ps->b_bottom = node;
		node->next = NULL;
	}
	else
	{
		node->next = ps->b_top;
		ps->b_top->prev = node;
		ps->b_top = node;
	}
	ps->b_size++;
	ps->a_size--;
	write(1, "pb\n", 3);
}
