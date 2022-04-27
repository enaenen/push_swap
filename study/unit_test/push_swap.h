/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:40 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 22:25:49 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ALLOC_ERROR 3

typedef struct s_stack_node_type {
	int		data;
	int		index;
	struct s_stack_node_type	*next;
} t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}t_stack;

int	error_handle(int type);

/* parsing */
void	ft_free_split(char **array);
int		get_size_split_str(char **split);
int		get_str_size(int argc, char **argv);
void	set_array(int *array, int *arr_index, char **str);
int		*parse_argv(int argc, char **argv);

/* stack manipulate */
int		push(t_stack *stack, int data);
t_node	*pop(t_stack *stack);
t_node	*peek(t_stack *stack);
/*TEST */
void	print_stack(t_stack *stack);


#endif