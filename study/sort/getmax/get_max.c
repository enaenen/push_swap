#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType {
	struct ListNodeType *next;
	int data;
}ListNode;

typedef struct LinkedListType {
	ListNode *head;
	int	cnt;
}LinkedList;


void	get_max_2(LinkedList *stack, int cnt, int *min, int *next_min)
{
	int				i;
	ListNode	*tmp;
	printf("DDD");
	i = 0;
	tmp = stack->head;
	*min = 2147483647;
	while (i++ < cnt)
	{
		if (*min > tmp->data)
		{
			*next_min = *min;
			*min = tmp->data;
		}
		else if (*next_min > tmp->data)
			*next_min = tmp->data;
		tmp = tmp->next;
	}
}
int	allocNode(LinkedList *pList, int data)
{

	ListNode *new;
	ListNode *original;

	new = calloc(1, sizeof(ListNode));
	new->data = data;
	original = pList->head;
	while (original)
		original = original->next;
	original = new;
	return 0;
}

void display(LinkedList *pList)
{
	ListNode *node = pList->head;
	while (node)
	{
		printf(" %d \n", node->data);
		node = node->next;
	}
}

int main(void)
{
	int				min[2];
	int				i;
	LinkedList		*stack;

	// printf("WW");
	stack = calloc(1, sizeof(LinkedList));
	allocNode(stack, 4);
	allocNode(stack, 10);
	allocNode(stack, 110);
	allocNode(stack, 1);
	display(stack);
	// get_max_2(stack, 4, &min[0], &min[1]);
	// printf("min[0] = %d min[1] = %d \n",min[0], min[1]);
}