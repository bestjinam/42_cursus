/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:41:17 by jinam             #+#    #+#             */
/*   Updated: 2022/11/04 15:32:49 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_main.h"
#include <stdlib.h>

int	pre_sorting_and_filtering(t_stacks *stacks)
{
	int	i;

	i = -1;
	stacks->array = malloc(sizeof(int) * stacks->buffer.len);
	if (!stacks->array)
		exit(1);
	ft_memcpy(stacks->array, stacks->buffer.buffer, \
			stacks->buffer.len * sizeof(int));
	merge_sort(0, stacks->buffer.len - 1, stacks);
	while (++i + 1 < stacks->buffer.len)
	{
		if (stacks->array[i] == stacks->array[i + 1])
			print_error();
	}
	return (0);
}

int	conv_str_to_int(char **str, t_stacks *stacks)
{
	int		i;
	long	num;
	int		flag;

	i = -1;
	flag = 0;
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
	if (pre_sorting_and_filtering(stacks) == -1)
		return (1);
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

int	main(int argc, char **argv)
{
	t_stacks	stks;

	if (argc < 1)
		return (0);
	if (read_argvs(argc, argv, &stks) == -1)
		exit (1);
	init_stacks(&stks);
	if (is_sorting(stks.array, stks.buffer.buffer, stks.buffer.len))
		exit (1);
	init_sorting(&stks);
	free(stks.array);
	stack_delete(&stks.buffer);
	stack_delete(&stks.stk_a);
	stack_delete(&stks.stk_b);
	exit(0);
}
