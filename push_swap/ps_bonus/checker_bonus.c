/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:17:06 by jinam             #+#    #+#             */
/*   Updated: 2022/11/04 15:31:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ds_bonus.h"

void	execute_cmd(char *str, t_stacks *stks)
{
	if (!ft_strncmp(str, "pa\n", ft_strlen(str) + 1))
		pa(stks);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str) + 1))
		pb(stks);
	else if (!ft_strncmp(str, "sa\n", ft_strlen(str) + 1))
		sa(stks);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str) + 1))
		sb(stks);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str) + 1))
		ss(stks);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str) + 1))
		ra(stks);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str) + 1))
		rb(stks);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str) + 1))
		rra(stks);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str) + 1))
		rrb(stks);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str) + 1))
		rrr(stks);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str) + 1))
		rr(stks);
	else
		print_error();
}

int	check_sorting(t_stack *stk, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (show_value(stk, 0, i - 1) > show_value(stk, 0, i))
			return (0);
	}
	return (1);
}

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

int	main(int argc, char **argv)
{
	t_stacks	stks;
	char		*str;

	if (argc < 2)
		return (0);
	if (read_argvs(argc, argv, &stks) == -1)
		return (1);
	init_stacks(&stks);
	pre_sorting_and_filtering(&stks);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		execute_cmd(str, &stks);
	}
	if (check_sorting(&stks.stk_a, stks.buffer.len))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_delete(&stks.buffer);
	stack_delete(&stks.stk_a);
	stack_delete(&stks.stk_b);
	free(stks.array);
	exit(0);
}
