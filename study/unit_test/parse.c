/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:20 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 21:21:15 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_split_str(char **split)
{
	int len;

	len = 0;
	while (split[len])
		len++;
	
	return (len);
}

void	ft_free_split(char **array)
{
	int	index;

	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
	array = NULL;
}

int	get_str_size(int argc, char **argv)
{
	int	index;
	int	size;
	int	check;
	char	**split;

	index = 0;
	size = 0;
	while (index < argc)
	{
		check = 0;
		while (argv[index][check])
		{
			if (!ft_isspace(argv[index][check]))
				break;
			check++;
		}
		if (argv[index][check] == '\0')
			error_handle(1);
		split = ft_split(argv[index], ' ');
		size += get_size_split_str(split);
		ft_free_split(split);
		index++;
	}
	return (size - 1);
}

void	set_array(int *array, int *arr_index, char **str)
{
	int num;
	int index;

	index = 0;
	while (str[index])
	{
		num = ft_atoi(str[index]);
		array[*arr_index] = num;
		(*arr_index)++;
		index++;
	}
}

int	*parse_argv(int argc, char **argv)
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
	return (new);
}
