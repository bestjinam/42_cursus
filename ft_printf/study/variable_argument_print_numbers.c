/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_argument_print_numbers.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:30:35 by jinam             #+#    #+#             */
/*   Updated: 2022/08/01 15:11:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	print_numbers(int args, ...)
{
	va_list	ap;
	int		i;
	int		num;

	va_start(ap, args);
	i = 0;
	while (i < args)
	{
		num = va_arg(ap, int);
		printf("%d ", num);
		i ++;
	}
	va_end(ap);
	printf("\n");
}

int	main(void)
{
	print_numbers(1, 10);
	print_numbers(2, 10, 20);
	print_numbers(3, 10, 20, 30);
	print_numbers(4, 10, 20, 30, 40);
	return (0);
}
