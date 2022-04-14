#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define	FALSE	(0)
#define TRUE	(1)

typedef struct s_node 
{
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
} Node;

typedef struct	s_head
{
	int		count;
	struct node	*head;
} Head;

int is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c =='\v' || c == '\r' || c == '\f' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_char_num(char c)
{
	if ('0' <= c || c <= '9' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int	is_str_num(char *str)
{
	while (*str)
	{
		if (is_char_num(*str))
			str++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	*seperate_num(char	*str)
{
	int	size;
	int	*ret;

	size = 0;
	while (*str)
	{
		if (!is_whitespace(*str) && is_char_num(*str))
			size++;
		str++;
	}
	ret = (int *)malloc(sizeof(int) * size + 1);
	if (!ret)
	{
		printf("Malloc Error\n");
		exit (-1);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char	**input;
	int		tmp;
	int		*num_arr;

	input = ++argv;
	if (argc <= 1)
		printf("Input nums. \n");
		
	while (*input)
	{	
		if (!is_str_num(*input))
		{
			printf("You can use only Integer \n");
			exit(0);
		}
		num_arr = seperate_num(*input);
		tmp = atoi(*input);
		printf(" %d \n", tmp);
		input++;
	}
}
