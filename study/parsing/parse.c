#include "parse.h"

int	error_handle(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

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

int	*parse_argv(int argc, char **argv, int size)
{
	int		argc_index;
	int		array_index;
	int		*new;
	char	**split;

	argc_index = 1;
	array_index = 0;
	new = (int *)malloc(sizeof(int) * size);
	if (!new)
		error_handle(1);
	while (argc_index < argc)
	{
		split = ft_split(argv[argc_index], ' ');
		set_array(new, &array_index, split);
		ft_free_split(split);
		argc_index++;
	}
	new[array_index] = '\0';
	return (new);
}


int main(int argc, char **argv)
{
	int		*arr;
	int		size;
	int		*array;
	
	// arr = (int *)malloc(sizeof(int));
	if (argc < 2)
		error_handle(-1);
	size = get_str_size(argc, argv);
	array = parse_argv(argc, argv, size);
	for (int i =0; array[i]; i++)
	{
		printf("i =  %d  --> %d", i, array[i]);
	}
	
}