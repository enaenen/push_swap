/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:42:25 by wchae             #+#    #+#             */
/*   Updated: 2022/05/01 18:42:34 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_command(t_stack *a, t_stack *b, char *str)
{
	if (!a || !b)
		return ;
	if (a->size < 2 || b->size < 2)
		return ;
	else if (!ft_strcmp(str, "ss") && swap_top(a) && swap_top(b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "rr") && rotate(a) && rotate(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rrr") && reverse_rotate(a) && reverse_rotate(b))
		write(1, "rrr\n", 4);
}

void	command(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "pa") && trade_push(b, a))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && trade_push(a, b))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "sa") && swap_top(a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && swap_top(b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ra") && rotate(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && rotate(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rra") && reverse_rotate(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && reverse_rotate(b))
		write(1, "rrb\n", 4);
}
