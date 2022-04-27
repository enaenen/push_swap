/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:17 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 22:31:28 by wchae            ###   ########.fr       */
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

void	array_to_stack(t_stack *stack, int *array)
{
	int		i;

	i = 0;
	printf("%d\n", array[i]);
	while (array[i])
	{
		push(stack, array[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack;
	
	stack = NULL;
	if (argc < 2)
		error_handle(-1);
	array = parse_argv(argc, argv);
	array_to_stack(stack, array);
	print_stack(stack);
}