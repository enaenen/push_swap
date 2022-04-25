/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:06:01 by wchae             #+#    #+#             */
/*   Updated: 2022/04/25 16:43:06 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->a_size < 2)
		return ;
	node = ps->a_top;
	ps->a_top = ps->a_top->next;
	ps->a_top->prev = NULL;
	ps->a_bottom->next = node;
	node->prev = ps->a_bottom;
	ps->a_bottom = node;
	ps->a_bottom->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->b_size < 2)
		return ;
	node = ps->b_top;
	ps->b_top = ps->b_top->next;
	ps->b_top->prev = NULL;
	ps->b_bottom->next = node;
	node->prev = ps->b_bottom;
	ps->b_bottom = node;
	ps->b_bottom->prev = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	t_stack_node	*node;

	if (ps->a_size < 2 || ps->b_size < 2)
		return ;
	node = ps->a_top;
	ps->a_top = ps->a_top->next;
	ps->a_top->prev = NULL;
	ps->a_bottom->next = node;
	node->prev = ps->a_bottom;
	ps->a_bottom = node;
	ps->a_bottom->next = NULL;
	node = ps->b_top;
	ps->b_top = ps->b_top->next;
	ps->b_top->prev = NULL;
	ps->b_bottom->next = node;
	node->prev = ps->b_bottom;
	ps->b_bottom = node;
	ps->b_bottom->prev = NULL;
	write(1, "rr\n", 4);

}