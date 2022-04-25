/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:55:27 by wchae             #+#    #+#             */
/*   Updated: 2022/04/25 16:40:17 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_ps *ps)
{
	int	n;
	
	if (ps->a_size < 2)
		return ;
	n = ps->a_top->data;
	ps->a_top->data = ps->a_top->next->data;
	ps->a_top->next->data = n;
	write(1, "sa\n", 3);
}

void	sb(t_ps *ps)
{
	int	n;
	
	if (ps->b_size < 2)
		return ;
	n = ps->b_top->data;
	ps->b_top->data = ps->b_top->next->data;
	ps->b_top->next->data = n;
	write(1, "sb\n", 3);
}

void	ss(t_ps *ps)
{
	int	n;

	if (ps->a_size < 2 || ps->b_size < 2)
		return ;
	n = ps->a_top->data;
	ps->a_top->data = ps->a_top->next->data;
	ps->a_top->next->data = n;
	n = ps->b_top->data;
	ps->b_top->data = ps->b_top->next->data;
	ps->b_top->next->data = n;
	write(1, "ss\n", 3);
}
