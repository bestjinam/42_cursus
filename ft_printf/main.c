#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>

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
	//test1 = ft_printf(">>ft %10c d test : 1. %c\n", '0', 'f');
	//test2 = printf(">>ft %10c d test : 1. %c\n", '0', 'f');
	//test1 =  ft_printf("%.1s, %.1s, %.1s, %.1s", NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	//test1=  ft_printf("1. (+)%+.5d 2. (-)%-d, 3.% d, 4.%.5d 5.%.d \n", 42, -42, 42, 42, 42);
	//test1 = printf("1.%+10.5d 2.%+10.5d \n", -10, 0);
	//test2 = ft_printf("1.%+10.5d 2.%+10.5d \n", -10, 0);
	//test1 = printf("%15p\n", NULL);
	//test2 = ft_printf("%15p\n", NULL);
	//test1 = printf(" %-9p %-10p\n", LONG_MIN, LONG_MAX);
	//test2 = ft_printf(" %-9p %-10p\n", LONG_MIN, LONG_MAX);
	test1 = printf("%#X\n",0);
	test2 = ft_printf("%#X\n",0);
	printf("\n%d\n", test1);
	printf("%d\n", test2);
}
