#include <stdlib.h>
#include <stdio.h>

typedef struct s_test
{
	int	*nums;
}	t_test;

void testf(int **t);

int	main(void)
{
	t_test test;
	t_test *ptest = &test;

	testf(&ptest->nums);
	int i = 0;
	while (ptest->nums[i])
	{
		printf("%d\n", ptest->nums[i]);
		i ++;
	}
}

void testf(int **t)
{
	*t = malloc(sizeof(int) * 4);
	(*t)[0] = 1;
	(*t)[1] = 2;
	(*t)[2] = 3;
	(*t)[3] = 0;
}
