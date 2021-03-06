/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:40 by wchae             #+#    #+#             */
/*   Updated: 2022/05/02 22:33:17 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ALLOC_ERROR 3

typedef struct s_stack_node_type {
	int							data;
	int							index;
	struct s_stack_node_type	*next;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

void		error_handle(int type);
int			is_ascending(t_stack *stack, int cnt);
/* Input Size Check */
int			get_size_split_str(char **split);
int			get_str_size(int argc, char **argv);
/* Parsing  */
void		ft_free_split(char **array);
void		set_array(int *array, int *arr_index, char **str);
t_stack		*parse_argv(int argc, char **argv);
t_stack		*array_to_stack(int *array, int arr_size);
/* Original Stack Manipulate */
int			push(t_stack *stack, t_node element);
t_node		*pop(t_stack *stack);
t_node		*peek(t_stack *stack);
/*  Push Swap Manipulate  */
int			reverse_push(t_stack *stack, t_node element);
int			swap_top(t_stack *stack);
int			trade_push(t_stack *from, t_stack *to);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);
void		command(t_stack *a, t_stack *b, char *str);
void		rotate_both_command(t_stack *a, t_stack *b, char *str);
/* Sort */
void		sort_2(t_stack	*a);
void		sort_3(t_stack	*a);
void		indexing_stack(t_stack *stack);
t_node		*get_min_value_node(t_stack *stack);
void		sort_5(t_stack	*a, t_stack *b);
void		sort_4(t_stack	*a, t_stack *b);
void		sort_big(t_stack *a, t_stack *b);

#endif
