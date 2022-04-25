/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revsers_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:41:21 by wchae             #+#    #+#             */
/*   Updated: 2022/04/25 16:44:10 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->a_size < 2)
		return;
	node = ps->a_bottom;
	ps->a_bottom = ps->a_bottom->prev;
	ps->b_bottom->next = NULL;
	ps->a_top->prev = node;
	node->next = ps->a_top;
	node->prev = NULL;
	ps->a_top = node;
	write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	t_stack_node	*node;
	
	if (ps->b_size < 2)
		return ;
	node = ps->b_bottom;
	ps->b_bottom = ps->a_bottom;
	ps->b_bottom->next = NULL;
	node->next = ps->a_top;
	node->prev = NULL;
	ps->b_top->prev = node;
	ps->b_top = node;
	write(1, "rrb\n", 4);
}

void	rrr(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->a_size < 2 || ps->b_size < 2)
		return ;
	node = ps->a_bottom;
	ps->a_bottom = ps->a_bottom->prev;
	ps->b_bottom->next = NULL;
	ps->a_top->prev = node;
	node->next = ps->a_top;
	node->prev = NULL;
	ps->a_top = node;
	node = ps->b_bottom;
	ps->b_bottom = ps->a_bottom;
	ps->b_bottom->next = NULL;
	node->next = ps->a_top;
	node->prev = NULL;
	ps->b_top->prev = node;
	ps->b_top = node;
	write(1, "rrr\n", 4);
}
