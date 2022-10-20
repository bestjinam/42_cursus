/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:42:02 by jinam             #+#    #+#             */
/*   Updated: 2022/10/20 18:56:36 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
int	_filtering_sorting(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->buffer.len)
	{
		j = i;
		while (++j < stacks->buffer.len)
			if (stacks->buffer.buffer[i] == stacks->buffer.buffer[j])
				return (-1);
	}
	return (0);
}

int	__conv_str_to_int(char **str, t_stack *buffer)
{
	int		i;
	long	num;

	i = -1;
	while (str[++i])
	{
		num = ft_atol_base(str[i], "0123456789");
		if (num == 0 && ft_memcmp("0", str[i], ft_strlen(str[i])))
			return (-1);
		else if (-2147483648 > num || num > 2147483647)
			return (-1);
		printf("num : %ld\n", num);
		stack_append(buffer, num);
	}
	return (0);
}

int	_read_argvs(int argc, char **argv, t_stack *buffer)
{
	int		i;
	char	**tmp;
	int		num;

	stack_init(buffer, 500);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || (tmp && !*tmp))
			return (-1);
		if (__conv_str_to_int(tmp, buffer) == -1)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	} 
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (-1);
	if (_read_argvs(argc, argv, &stacks.buffer) == -1)
		return (-1);
	printf("%ld\n", stacks.buffer.len);
}
