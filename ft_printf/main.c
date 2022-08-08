#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int	temp;

	temp = ft_printf("%s", (char *)NULL);
	printf("\n>> %d\n", temp);
	system("leaks a.out");
	return 0;
}
