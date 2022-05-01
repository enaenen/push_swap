/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:20 by wchae             #+#    #+#             */
/*   Updated: 2022/05/01 18:37:47 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoil(const char *str)
{
	long long	result;
	int			sign;
	int			valid;

	result = 0;
	sign = 1;
	valid = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		valid++;
	}
	result = result * sign;
	if (*str != '\0' || 10 < valid
		|| 2147483647 < result || result < -2147483648)
		error_handle(1);
	return ((int)result);
}

void	set_array(int *array, int *arr_index, char **str)
{
	int	num;
	int	index;

	index = 0;
	while (str[index])
	{
		num = ft_atoil(str[index]);
		array[*arr_index] = num;
		(*arr_index)++;
		index++;
	}
}

t_stack	*array_to_stack(int *array, int arr_size)
{
	int		i;
	t_stack	*stack;
	t_node	element;

	i = arr_size - 1;
	stack = ft_calloc(1, sizeof(t_stack));
	while (0 <= i)
	{
		element.data = array[i];
		push(stack, element);
		i--;
	}
	free(array);
	return (stack);
}

t_stack	*parse_argv(int argc, char **argv)
{
	int		i;
	int		array_index;
	int		*new;
	char	**split;

	i = get_str_size(argc, argv);
	array_index = 0;
	new = (int *)malloc(sizeof(int) * i);
	if (!new)
		error_handle(1);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		set_array(new, &array_index, split);
		ft_free_split(split);
		i++;
	}
	new[array_index] = '\0';
	return (array_to_stack(new, array_index));
}