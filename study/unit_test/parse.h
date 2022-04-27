/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:04:26 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 21:09:54 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
#include "ps.h"

int		*parse_argv(int argc, char **argv, int size);
int		get_size_split_str(char **split);
void	ft_free_split(char **array);
int		get_str_size(int argc, char **argv);
void	set_array(int *array, int *arr_index, char **str);
int		*parse_argv(int argc, char **argv, int size);

#endif