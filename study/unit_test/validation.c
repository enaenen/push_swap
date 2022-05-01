/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:37:28 by wchae             #+#    #+#             */
/*   Updated: 2022/05/01 18:37:58 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_split_str(char **split)
{
	int	len;

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

void	ft_isonlyspace(char *str)
{
	int	check;

	check = 0;
	while (str[check])
	{
		if (!ft_isspace(*str))
			break ;
		check++;
	}
	if (*str == '\0')
		error_handle(1);
}

int	get_str_size(int argc, char **argv)
{
	int		index;
	int		size;
	char	**split;

	index = 0;
	size = 0;
	while (index < argc)
	{
		ft_isonlyspace(argv[index]);
		split = ft_split(argv[index], ' ');
		size += get_size_split_str(split);
		ft_free_split(split);
		index++;
	}
	return (size - 1);
}
