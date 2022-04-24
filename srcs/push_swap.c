/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:48:01 by wchae             #+#    #+#             */
/*   Updated: 2022/04/24 11:37:06 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
int	error_handle()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
t_stack_node	*init_stack_node(void)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		error_handle();
	new->next = NULL;
	new->prev = NULL;
	new->data = 0;
	return (new);
}

t_ps	*init_push_swap(void)
{
	t_ps			*ps;
	t_stack_node	*stack_a;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		error_handle();
	stack_a = init_stack_node();
	ps->array = NULL;
	ps->a_top = stack_a;
	ps->a_bottom = stack_a;
	ps->a_size = 0;
	ps->b_size = 0;
	return (ps);
}
/*split free */
void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

int	parse_argv(int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		size;
	
	i = 0;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j++]))
				break;
		}
		if (argv[i][j] == '\0')
			error_handle();
		split = ft_split(argv[i], ' ');
		size += ft_strcnt(split);
		free_split(split);
		i++;
	}
	return (size - 1);
}

/* main*/
int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		error_handle();
	arr_size = 0;
	ps = init_push_swap();
	arr_size = parse_argv(argc, argv);
}
