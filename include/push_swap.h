/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:45:50 by wchae             #+#    #+#             */
/*   Updated: 2022/04/14 13:57:20 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Dependencies
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#include "../lib/libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_stack_node
{
	int		data;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

typedef struct s_stack
{
	int				count;
	t_stack_node	*head;
	t_stack_node	*tail;
}	t_stack;

typedef struct	s_ps
{
	int		count;
	t_stack a;
	t_stack b;
}	t_ps;

typedef struct s_pv
{
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	pa_cnt;
	int	pv_s;
	int	pv_l;
	int	pv_s_count;
	int	pv_l_count;
	int	*arr;
}	t_pv;

#endif