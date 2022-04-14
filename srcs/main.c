/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:45:12 by wchae             #+#    #+#             */
/*   Updated: 2022/04/14 16:57:07 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	erorr_handle(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int		is_split(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+' || str[i] == '-')
			if(!ft_isdigit(str[i + 1]))
				erorr_handle();
		if (str[i] == ' ')
			ret = TRUE;
		i++;
	}
	if (str[i] != '\0')
		erorr_handle();
	return (ret);
}

void free_dptr_str(char **str)
{
	int i;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

t_stack_node	*new_node(int	data)
{
	t_stack_node	*node;
	node = (t_stack_node*) malloc(sizeof(t_stack_node));
	if (!node)
		erorr_handle();
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	stack_add_back(t_stack *stack, t_stack_node *new_node)
{
	if (stack->count == 0)
	{
		stack->head = new_node;
		stack->tail = stack->head;
	}
	else
	{
		stack->tail->next = new_node;
		stack->tail = new_node;
		new_node->prev = stack->tail;
	}
	stack->count++;
}

void	init_stack_data(char *str, t_stack *stack)
{
	long long		data;
	t_stack_node	*tmp;

	if (11 < ft_strlen(str))
		erorr_handle();
	data = ft_atoi(str);
	if (2147483647 < data || data < -2147483648)
		erorr_handle();
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == (int)data)
			erorr_handle();
		tmp = tmp->next;
	}
	stack_add_back(stack, new_node(data));
}

void	parse(int argc, char **argv, t_ps *stack)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (i++ < argc - 1)
	{
		if (is_split(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split[j])
				init_stack_data(split[j++], &stack->a);
			free_dptr_str(split);
		}
		else
			init_stack_data(argv[i], &stack->a);
	}
}

int		main(int argc, char **argv)
{
	t_ps	stack;
	t_stack_node *node;

	ft_bzero(&stack, sizeof(t_ps));
	parse(argc, argv, &stack);
	node = stack.a.head;
	while (node){
		printf(" %d ", node->data);
		node = node->next;
	}
	return 0;
}