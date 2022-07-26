/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:42:02 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 11:37:46 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

static int	_filtering_sorting(t_stacks *stacks)
{
	int	i;

	i = -1;
	stacks->array = malloc(sizeof(int) * stacks->buffer.len);
	if (!stacks->array)
		return (-1);
	ft_memcpy(stacks->array, stacks->buffer.buffer, \
			stacks->buffer.len * sizeof(int));
	merge_sort(0, stacks->buffer.len - 1, stacks);
	/*while (++i + 1 < stacks->buffer.len)
	{
		printf("pre_sorting %d: %d vs %d: %d\n", i, stacks->array[i], i, stacks->array[i]);
		
		//if (stacks->array[i] == stacks->array[i + 1])
		//	return (-1);
	}
	*/
	return (0);
}

static int	__conv_str_to_int(char **str, t_stacks *stacks)
{
	int		i;
	long	num;

	i = -1;
	while (str[++i])
	{
		num = ft_atol_base(str[i], "0123456789");
		if (num == 0 && ft_memcmp("0", str[i], ft_strlen(str[i]) != 0))
			return (-1);
		else if (-2147483648 > num || num > 2147483647)
			return (-1);
		stack_append(&stacks->buffer, num);
		free(str[i]);
	}
	return (0);
}

static int	_read_argvs(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	char	**tmp;

	stack_init(&stacks->buffer, 500);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || (tmp && !*tmp))
			return (-1);
		if (__conv_str_to_int(tmp, stacks) == -1)
			exit(0);
		free(tmp);
	}
	if (_filtering_sorting(stacks) == -1)
		return (-1);
	
	return (0);
}

static void	_init_stacks(t_stacks *stacks)
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (-1);
	if (_read_argvs(argc, argv, &stacks) == -1)
		return (-1);
	_init_stacks(&stacks);
	init_sorting(&stacks);
	free(stacks.array);
	stack_delete(&stacks.buffer);
	stack_delete(&stacks.stk_a);
	stack_delete(&stacks.stk_b);
	//stack_delete(&stacks.commands);
	exit(0);
}

