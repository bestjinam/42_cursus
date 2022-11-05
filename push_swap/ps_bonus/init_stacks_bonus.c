/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:48:32 by jinam             #+#    #+#             */
/*   Updated: 2022/11/04 15:31:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"

int	conv_str_to_int(char **str, t_stacks *stacks)
{
	int		i;
	long	num;
	int		flag;

	flag = 1;
	i = -1;
	while (str[++i])
	{
		num = ft_atol_base(str[i], "0123456789", &flag);
		if (flag == -1)
			print_error();
		if ((ft_memcmp("-", str[i], ft_strlen(str[i])) == 0) \
			|| ft_memcmp("+", str[i], ft_strlen(str[i])) == 0)
			print_error();
		else if (-2147483648 > num || num > 2147483647)
			print_error();
		stack_append(&stacks->buffer, num);
		free(str[i]);
	}
	return (0);
}

int	read_argvs(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	char	**tmp;

	stack_init(&stacks->buffer, 500);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || (tmp && !*tmp))
			print_error();
		conv_str_to_int(tmp, stacks);
		free(tmp);
	}
	return (0);
}

void	init_stacks(t_stacks *stacks)
{
	int	i;

	stack_init(&stacks->stk_a, stacks->buffer.len);
	stack_init(&stacks->stk_b, stacks->buffer.len);
	i = -1;
	while (++i < stacks->buffer.len)
	{
		add_rear(&stacks->stk_a, stacks->buffer.buffer[i]);
	}
}
