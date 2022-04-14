#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int ret;

	while (*argv)
	{
		ret = atoi(*argv);
		printf("%s ==  %d \n", *argv, ret);
		argv++;
	}
	return 0;
}
