#include "ft_printf.h"

int main(void)
{
	int t;
	int t1;

	// c test
/*	t = ft_printf(" ft: %c %c %c ", 'a', '1', '2');
	printf("\n");
	t1 = printf("std: %c %c %c ", 'a', '1', '2');
	printf("\n");
	printf("ft: %d\n", t);
	printf("std: %d\n", t1); */
	// s test
	t = ft_printf(" NULL %s NULL ", NULL);
	printf("%d\n", t);
	return 0;
}
