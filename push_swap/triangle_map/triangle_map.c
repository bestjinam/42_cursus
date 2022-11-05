/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:47:07 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 15:46:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "triangle_map.h"
#include <stdlib.h>

static void	trg_map_init(t_triangle_map *map, int size);
static void	trg_map_fill_values(t_triangle_map *map, int idx, int size);
static void	trg_map_fill_molds(t_triangle_map *map, int idx, int size);

t_triangle_map	*trg_map_create(int size)
{
	t_triangle_map	*map;

	if (size <= 0)
		return (FT_NULL);
	map = malloc(sizeof(t_triangle_map));
	if (!map)
		return (FT_NULL);
	map->val = malloc(sizeof(int) * size * 3);
	map->mold = malloc(sizeof(char) * size * 3);
	if (!map->val || !map->mold)
	{
		trg_map_destroy(map);
		return (FT_NULL);
	}
	trg_map_init(map, size);
	return (map);
}

void	trg_map_init(t_triangle_map *map, int size)
{
	map->depth = 0;
	map->val[0] = size;
	map->size = 1;
	trg_map_fill_values(map, 0, 1);
	map->mold[0] = (map->depth % 2 == 0) * DOWN + (map->depth % 2 == 1) * UP;
	trg_map_fill_molds(map, 0, 1);
}

void	trg_map_fill_values(t_triangle_map *map, int idx, int size)
{
	const int	level_size = size * 2 + 1;
	const int	start = size;
	const int	mid = start - 1 + 2 * (level_size / 3);
	const int	end = start - 1 + level_size;
	int			i;

	i = 0;
	while (idx + i < start)
	{
		if (map->val[idx + i] <= 3)
			return ;
		map->val[start + i] = map->val[idx + i] / 3;
		map->val[mid - i] = map->val[idx + i] - 2 * (map->val[idx + i] / 3);
		map->val[end - i] = map->val[idx + i] / 3;
		i++;
	}
	map->depth++;
	map->size += level_size;
	trg_map_fill_values(map, start, size + level_size);
}

void	trg_map_fill_molds(t_triangle_map *map, int idx, int size)
{
	const int	level_size = size * 2 + 1;
	const int	start = size;
	const int	mid = start - 1 + 2 * (level_size / 3);
	const int	end = start - 1 + level_size;
	int			i;

	i = 0;
	while (idx + i < start)
	{
		if (map->val[idx + i] <= 3)
			return ;
		map->mold[start + i] = map->mold[idx + i];
		map->mold[mid - i] = (map->mold[idx + i] + 1) % 2;
		map->mold[end - i] = (map->mold[idx + i] + 1) % 2;
		i++;
	}
	trg_map_fill_molds(map, start, size + level_size);
}

void	trg_map_destroy(t_triangle_map *map)
{
	free(map->val);
	free(map->mold);
	free(map);
}
