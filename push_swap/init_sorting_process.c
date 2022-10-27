/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/28 07:08:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	merge_sorting_process(t_stacks *stacks)
{
	t_triangle_map	*map;
	const int		size = stacks->buffer.len;

	map = trg_map_create(size);
	stack_init(&stacks->commands, 1024);
	dividing_processing(stacks, map);
	conquering_processing(stacks, map);
}

int	init_sorting(t_stacks *stacks)
{
	t_min_max	min_max;

	get_max_min(stacks->array, stacks->buffer.len, &min_max);
	if (2 <= stacks->buffer.len && stacks->buffer.len <= 5)
		small_sorting_process(stacks, &min_max);
	else
		merge_sorting_process(stacks);
	return (1);
}
