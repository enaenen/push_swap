/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:17 by wchae             #+#    #+#             */
/*   Updated: 2022/05/01 18:24:29 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	error_handle(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

/*
int main(int argc, char **argv)
{
	// int		*array;
	t_stack	*stack;
	t_stack	*stackB;

	if (argc < 2)
		error_handle(-1);
	stack = parse_argv(argc, argv);

	stackB = ft_calloc(1, sizeof(t_stack));
	printf("\n");
	// swap_top(stack);
	trade_push(stack, stackB);
	// print_stack(stackB);
	print_stack(stack);	
	printf("\n====\n");
	print_stack(stackB);
	
	system("leaks push_swap");
}
*/