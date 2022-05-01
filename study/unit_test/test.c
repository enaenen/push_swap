#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stackB;

	if (argc < 2)
		error_handle(-1);
	stack = parse_argv(argc, argv);

	stackB = ft_calloc(1, sizeof(t_stack));
	printf("\n");
	// swap_top(stack);
	// trade_push(stack, stackB);
	// print_stack(stackB);

	command(stack, NULL, "ra");
	command(stack, NULL, "rra");
	rotate_both_command(stack, stackB, "rrr");
	
	command(stack, stackB, "pb");
	command(stack, stackB, "pb");
	//345678910
	rotate_both_command(stack, stackB, "rrr");


//10 3 4 5 6 7 8 9
	printf("stack A ==");
	print_stack(stack);	
	// 1 2 
	printf("stack B ==");
	print_stack(stackB);
	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp |grep leaked && rm -rf leaks_result_temp");
}