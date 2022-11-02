/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:04 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 15:07:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sorting.h"

void	merge_sorting_process(t_stacks *stacks)
{
	t_triangle_map	*map;
	const int		size = stacks->buffer.len;

	map = trg_map_create(size);
	dividing_processing(stacks, map);
	conquering_processing(stacks, map);
	trg_map_destroy(map);
}

int	init_sorting(t_stacks *stacks)
{
	if (2 <= stacks->buffer.len && stacks->buffer.len <= 5)
		small_sorting_process(stacks);
	else
		merge_sorting_process(stacks);
	return (1);
}
