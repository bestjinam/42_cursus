/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:34:27 by jinam             #+#    #+#             */
/*   Updated: 2022/11/02 13:17:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "triangle_map.h"

int	trg_map_get_level_start_idx(int depth)
{
	int	i;
	int	start_idx;

	i = -1;
	start_idx = 0;
	while (++i < depth)
		start_idx = 3 * start_idx + 1;
	return (start_idx);
}

void	trg_map_show_1(const t_triangle_map *map, int cur_depth, int idx)
{
	int	i;

	if (cur_depth > map->depth)
		return ;
	i = -1;
	while (++i < cur_depth)
		ft_printf("    ");
	if (cur_depth > 0)
		ft_printf("+--");
	if (map->mold[idx] == UP)
		ft_printf("%d(%dU)\n", map->val[idx], cur_depth);
	else
		ft_printf("%d(%dD)\n", map->val[idx], cur_depth);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 1);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 2);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 3);
}

void	trg_map_show_2(const t_triangle_map *map)
{
	const int	start = trg_map_get_level_start_idx(map->depth);
	const int	size = 2 * start + 1;
	int			i;

	i = -1;
	while (++i < size)
	{
		if (map->mold[start + i] == UP)
			ft_printf("%d(%dU)\n", map->val[start + i], map->depth);
		else
			ft_printf("%d(%dD)\n", map->val[start + i], map->depth);
	}
}
