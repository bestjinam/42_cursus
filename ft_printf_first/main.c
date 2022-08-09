#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int	temp;

	//temp = ft_printf("%s", (char *)NULL);
	ft_printf("%2147483648d\n>>\n", 10);
	system("leaks a.out");
	return 0;
}
