/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:45:44 by wchae             #+#    #+#             */
/*   Updated: 2022/04/24 11:03:30 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;	
}	t_stack_node;

typedef struct s_push_swap
{
	int					*array;
	int					a_size;
	int					b_size;
	t_stack_node		*a_top;
	t_stack_node		*a_bottom;
	t_stack_node		*b_top;
	t_stack_node		*b_bottom;

}	t_ps;
# define TRUE 1
# define FALSE 0
#endif