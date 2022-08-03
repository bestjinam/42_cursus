#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	int	test1;
	int	test2;
	char *str = NULL;
	//1. char check;
	//test1 = ft_printf("ft c -> 1234 1234 test : 1. %c 2. %c\n", 'a', 'b');
	//test2 = printf("std -> 1234 1234 test : 1. %c 2. %c\n", 'a', 'b');
	//2. str check;
	int a = 10;
	test1 = ft_printf(">>ft d test : 1. %x\n", -1000);
	test2 = printf(">>std d test : 1. %x\n", -1000);
	printf("\n%d\n", test1);
	printf("%d\n", test2);
}
