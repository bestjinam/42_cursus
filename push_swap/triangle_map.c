/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:47:07 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 15:17:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle_map.h"

static void	triangle_map_fill(t_triangle_map *map, int idx)
{
	const int	level_size = map->size * 2 + 1;
	const int	start_idx = map->size;
	const int	mid_idx = start_idx - 1 + 2 * (level_size / 3);
	const int	end_idx = start_idx - 1 + level_size;
	int			i;

	if (map->values[idx] <= 5)
		return ;
	map->depth ++;
	map->size += level_size;
	i = 0;
	while (idx + i < start_idx)
	{
		map->values[start_idx + i] = map->values[idx + i] / 3;
		map->values[mid_idx - i] = map->values[idx + i] - 2 \
								* (map->values[idx + i] / 3);
		map->values[end_idx - i] = map->values[idx + i] / 3;
		map->shapes[start_idx + i] = map->shapes[idx + i];
		map->shapes[mid_idx - i] = (map->shapes[idx + i] + 1) % 2;
		map->shapes[end_idx - i] = (map->shapes[idx + i] + 1) % 2;
		i ++;
	}
	triangle_map_fill(map, start_idx);
}

void	triangle_map_destroy(t_triangle_map *map)
{
	free(map->values);
	free(map->shapes);
	free(map);
}

t_triangle_map	*triangle_map_create(int size)
{
	t_triangle_map	*new_map;

	new_map = malloc(sizeof(t_triangle_map));
	if (size <= 0 || !new_map)
		return (NULL);
	new_map->values = malloc(sizeof(int) * size);
	new_map->shapes = malloc(sizeof(char) * size);
	if (!new_map->values || !new_map->shapes)
	{
		triangle_map_destroy(new_map);
		return (NULL);
	}
	new_map->values[0] = size;
	new_map->shapes[0] = UP;
	new_map->depth = 0;
	new_map->size = 1;
	triangle_map_fill(new_map, 0);
	return (new_map);
}
