/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_argument_multiple_types.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:49:36 by jinam             #+#    #+#             */
/*   Updated: 2022/08/01 16:05:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	print_values(char *types, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, types);
	while (types[i])
	{
		if (types[i] == 'i')
			printf("%d ", va_arg(ap, int));
		else if (types[i] == 'd')
			printf("%f ", va_arg(ap, double));
		else if (types[i] == 'c')
			printf("%c ", va_arg(ap, int));
		else if (types[i] == 's')
			printf("%s ", va_arg(ap, char *));
		i ++;
	}
	va_end(ap);
	printf("\n");
}

int	main(void)
{
	print_values("i", 10);
	print_values("ci", 'a', 10);
	print_values("sicd", "hello, world!", 10, 'a', 1.234567);
	return (0);
}
