/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:48:01 by wchae             #+#    #+#             */
/*   Updated: 2022/04/27 15:57:25 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

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

int	get_argv_size(int argc, char **argv)
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
			if (!ft_isspace(argv[i][j]))
				break;
			j++;
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

void	set_arr(int	*arr, int *arr_index, char **split)
{
	int n;
	int i;

	i = 0;
	while (split[i])
	{
		n = ft_atoi(split[i]);
		arr[*arr_index] = n;
		(*arr_index)++;
		i++;
	}
}

int	*argv_to_array(int argc, char **argv, int size)
{
	char	**split;
	int		*new;
	int		argc_index;
	int		arr_index;

	argc_index = 1;
	arr_index = 0;
	new = (int *)malloc(sizeof(int) * size);
	if (!new)
		error_handle();
	while (argc_index < argc)
	{
		split = ft_split(argv[argc_index], ' ');
		set_arr(new, &arr_index, split);
		free_split(split);
		argc_index++;
	}
	new[arr_index] = '\0';
	return (new);
}

t_stack_node	*create_stack_node(void)
{
	t_stack_node *new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	new->data = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	arr_to_stack(int *arr, int arr_size, t_ps *ps)
{
	t_stack_node	*new;
	int				i;

	i = 0;
	while (i < arr_size)
	{
		new = create_stack_node();
		ps->a_bottom->data = arr[i];
		ps->a_bottom->next = new;
		new->prev = ps->a_bottom;
		ps->a_size++;
		ps->a_bottom = new;
		i++;
	}
	ps->a_bottom = ps->a_bottom->prev;
	free(new);
}

void	check_arr(int *arr, int arr_size)
{
	int i;
	int j;
	int cnt;
	int swap;

	cnt = 0;
	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size - 1)
		{
			if (arr[j + 1] < arr[j])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
				cnt++;
			}
			j++;
		}
		if (arr[i] == arr[i + 1])
			error_handle();
		i++;
	}
	if (!cnt)
		exit (1);
}

	
void	print_arr(t_ps *ps, int size)
{
	for (int i = 0; i < size; i++)
	{ 
		printf("%d ", ps->array[i]);
	}
}

void	parse_argv(int argc, char **argv, t_ps *ps)
{
	int	arr_size;
	int	*arr;

	arr_size = get_argv_size(argc, argv);
	arr = argv_to_array(argc, argv, arr_size);
	arr_to_stack(arr,arr_size ,ps);
	check_arr(arr, arr_size);
	ps->array = arr;
	print_arr(ps, arr_size);
}

void	sort_3(t_ps *ps)
{
	int top;
	int mid;
	int bot;

	top = ps->a_top->data;
	mid = ps->a_top->next->data;
	bot = ps->a_bottom->data;

	if (bot < mid && mid < top && bot < top)
	{
		sa(ps);
		rra(ps);
	}
	else if (mid < bot && bot < top && mid < top)
		ra(ps);
	else if (mid < top && top < bot && mid < bot)
		sa(ps);
	else if (bot < top && top < mid && bot < mid)
		rra(ps);
	else if (top < bot && bot < mid && top < mid)
	{
		sa(ps);
		ra(ps);
	}
}

void	divide_to_3(t_ps *ps)
{
	int i;
	int pv1;
	int pv2;

	i = ps->a_size / 3;
	pv1 = ps->array[i];
	i = ps->a_size * 2 / 3;
	pv2 = ps->array[i];
	i = ps->a_size;
	while (i)
	{
		if (ps->a_top->data < pv1)
		{
			pb(ps);
			rb(ps);
		}
		else if (ps->a_top->data < pv2)
			pb(ps);
		else
			ra(ps);
		i--;
	}
}

int		get_stack_min(t_stack_node	*stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}
// 제일 작은값의 위치
// 
int		set_a_location_min(t_ps *ps)
{
	int ret;
	int i;
	int tmp;
	t_stack_node	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = ps->a_top;
	i = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->data;
		if (tmp == i)
			break;
		ret++;
		stack_a = stack_a->next;
	}
	if ((ps->a_size + 1) / 2 <= ret)
		ret = (ps->a_size - ret) * -1;
	return (ret);
}

int		get_stack_max(t_stack_node *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int		set_a_location_max(t_ps *ps)
{
	int i;
	int tmp;
	int ret;
	t_stack_node	*stack_a;

	tmp = 0;
	ret = 0;
	stack_a = ps->a_top;
	i = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->data;
		if (tmp == i)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if ((ps->a_size + 1) / 2 <= ret)
		ret = ((ps->a_size - ret) * -1);
	return (ret);
}

int		set_a_location_mid(t_ps *ps, int n)
{
	t_stack_node	*stack_a;
	int				ret;

	stack_a = ps->a_top;
	ret = 1;
	while (stack_a->next)
	{
		if (stack_a->data < n && n < stack_a->next->data)
			break;
		ret++;
		stack_a = stack_a->next;
	}
	if ((ps->a_size + 1) / 2 <= ret)
		ret = (ps->a_size - ret) * -1;
	return (ret);
}

int		set_a_location(t_ps *ps, int n)
{
	int	ret;

	if (n < get_stack_min(ps->a_top))
		ret = set_a_location_min(ps);
	else if (get_stack_max(ps->a_top) < n)
		ret = set_a_location_max(ps);
	else
		ret = set_a_location_mid(ps, n);
	return (ret);
}
int	get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_loc < 0)
		a_loc *= -1;
	if (a_loc + b_loc < a + b)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_ps *ps, int *a, int *b)
{
	int				a_loc;
	int				b_loc;
	int				i;
	t_stack_node	*stack_b;
	int	num;

	i = 0;
	stack_b = ps->b_top;
	while (i < ps->b_size)
	{
		num = stack_b->data;
		a_loc = set_a_location(ps, num);
		if ((ps->b_size + 1) / 2  <= i)
			b_loc = (ps->b_size - i ) * -1;
		else
			b_loc = i;
		if (i == 0 || get_bigger(*a, *b, a_loc, b_loc))
		{
			*a = a_loc;
			*b = b_loc;
		}
		stack_b = stack_b->next;
		i++;
	}
}
void	rotate_same(t_ps *ps, int *a, int *b)
{
	while (*a && *b && (0 < *a && 0 < *b))
	{
		rr(ps);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(ps);
		*a += 1;
		*b += 1;
	}
}

void	rotate_a(t_ps *ps, int *a)
{
	while (a)
	{
		if (0 < a)
		{
			ra(ps);
			a--;
		}
		else
		{
			rra(ps);
			a++;
		}
	}
}

void	rotate_b(t_ps *ps, int *b)
{
	while (b)
	{
		if (0 < b)
		{
			rb(ps);
			b--;
		}
		else
		{
			rrb(ps);
			b++;
		}
	}
}

void	ft_sort_big_last(t_ps *ps)
{
	int min;
	int min_loc;

	min = get_stack_min(ps->a_top);
	min_loc = set_a_location_min(ps);
	while (min_loc)
	{
		if (0 < min_loc)
		{
			ra(ps);
			min_loc--;
		}
		else
		{
			rra(ps);
			min_loc++;
		}
	}
}

void	sort_2(t_ps *ps)
{
	if (ps->a_size == 2)
	{
		if (ps->a_bottom->data < ps->a_top->data)
			sa(ps);
	}
}


void	ft_sort_big(t_ps *ps)
{
	int a;
	int b;

	divide_to_3(ps);
	while (3 < ps->a_size)
		pb(ps);
	if (ps->a_size == 2)
		sort_2(ps);
	if (ps->a_size == 3)
		sort_3(ps);
	while (ps->b_size)
	{
		a = 0;
		b = 0;
		get_min_rotate(ps, &a, &b);
		rotate_same(ps, &a, &b);
		rotate_a(ps, &a);
		rotate_b(ps, &b);
		pa(ps);
	}
	ft_sort_big_last(ps);
}

void	ft_sort(t_ps *ps)
{

	if (ps->a_size == 2)
		sort_2(ps);
	else if (ps->a_size == 3)
		sort_3(ps);
	else
		ft_sort_big(ps);
}


/* main*/
int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		error_handle();
	ps = init_push_swap();
	parse_argv(argc, argv, ps);
	// print_swap(ps);
	// ft_sort(ps);
}
