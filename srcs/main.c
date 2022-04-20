/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:45:12 by wchae             #+#    #+#             */
/*   Updated: 2022/04/20 23:23:52 by wchae            ###   ########.fr       */
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

void	is_duplicated(t_stack_node *node, int data)
{
	while (node)
	{
		if (node->data == data){
			erorr_handle();
		}
		node = node->next;
	}
}

void	check_arg(int argc, char **argv, t_ps *stack)
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

void	free_stack(t_ps	stack)
{
	t_stack_node	*tmp;

	while (stack.a.head)
	{
		tmp = stack.a.head;
		stack.a.head = stack.a.head->next;
		free(tmp);
	}
}

int		is_sorted(t_stack stack, int count)
{
	t_stack_node	*node;
	int				i;

	node = stack.head;
	i = 0;
	while (node->next && i < count)
	{
		if (node->data < node->next->data)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}

// ============================================print
void	print_node(t_stack_node	*node)
{
	while (node){
		printf(" %d ", node->data);
		node = node->next;
	}
}
// ============================================print


int		main(int argc, char **argv)
{
	t_ps	stack;
	// t_stack_node *node;

	ft_bzero(&stack, sizeof(t_ps));
	check_arg(argc, argv, &stack);
	
	if (is_sorted(stack.a, stack.count))
	{
		free_stack(stack);
		return (0);
	}
	// else if (is_decending(stack.a, stack.count) && stack.count != 5)
	// 	sort_decending();
	// else if (stack.count == 5)
	// 	sort


	print_node(stack.a.head);
	
	return 0;
}