#include "push_swap.h"
void indexing_test(int argc, char **argv)
{
	t_stack	*stack = parse_argv(argc, argv);
	t_stack	*stackB = ft_calloc(1, sizeof(t_stack));

	indexing_stack(stack);

	printf("stack A\n");
	print_stack(stack);	
	printf("\n==============\n");

	printf("stack B\n");
	print_stack(stackB);
	printf("\n==============\n");
	free(stack);
	free(stackB);
	printf("===========================indexing test end\n");
}

void sort_test(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stackB;

	stack = parse_argv(argc, argv);
	stackB = ft_calloc(1, sizeof(t_stack));
	printf("is acending = %d\n", is_ascending(stack, stack->size));

	if (stack->size < 3)
		sort_2(stack);
	if (stack->size == 3)
		sort_3(stack);

	printf("stack A\n");
	print_stack(stack);	
	printf("\n==============\n");

	printf("stack B\n");
	print_stack(stackB);
	printf("\n==============\n");
	free(stack);
	free(stackB);
	printf("===========================sort test end\n");
}
void manipulate_unit_test(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stackB;

	
	printf("===========================manipulate start\n");
	stack = parse_argv(argc, argv);
	stackB = ft_calloc(1, sizeof(t_stack));
	command(stack, NULL, "ra");
	command(stack, NULL, "rra");
	rotate_both_command(stack, stackB, "rrr");

	command(stack, stackB, "pb");
	command(stack, stackB, "pb");
	//345678910
	rotate_both_command(stack, stackB, "rrr");

	printf("stack A ==");
	print_stack(stack);	

	printf("stack B ==");
	print_stack(stackB);
	free(stack);
	free(stackB);
	printf("\n===========================manipulate end\n");

}
void	sort_5_test(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	
	printf("===========================sort5 start\n");
	a = parse_argv(argc, argv);
	b = ft_calloc(1, sizeof(t_stack));
	indexing_stack(a);
	sort_5(a, b);

	printf("stack A\n");
	print_stack(a);	

	printf("stack B \n");
	print_stack(b);
	free(a);
	free(b);
}

int main(int argc, char **argv)
{

	if (argc < 2)
		error_handle(-1);

	// swap_top(stack);
	// trade_push(stack, stackB);
	// print_stack(stackB);

	// manipulate_unit_test(argc, argv);
	// sort_test(argc, argv);
	// indexing_test(argc, argv);
	sort_5_test(argc, argv);

	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp |grep leaked && rm -rf leaks_result_temp");
}