/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:51:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/26 19:54:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "triangle_map.h"

static void	triangle_map_fill(t_triangle_map *map, int idx);
static int	triangle_map_get_depth(int size);

t_triangle_map	*triangle_map_create(int size)
{
	t_triangle_map	*map;

	if (size <= 2)
		return (NULL);
	map = malloc(sizeof(t_triangle_map));
	if (!map)
		return (NULL);
	map->values = malloc(sizeof(int) * size);
	map->shapes = malloc(sizeof(char) * size);
	if (!map->values || !map->shapes)
	{
		triangle_map_destroy(map);
		return (NULL);
	}
	map->depth = triangle_map_get_depth(size);
	map->values[0] = size;
	map->shapes[0] = (map->depth % 2 == 0) * DOWN + (map->depth % 2 == 1) * UP;
	map->size = 1;
	triangle_map_fill(map, 0);
	return (map);
}

static void	triangle_map_fill(t_triangle_map *map, int idx)
{
	const int	level_size = map->size * 2 + 1;
	const int	start_idx = map->size;
	const int	mid_idx = start_idx - 1 + 2 * (level_size / 3);
	const int	end_idx = start_idx - 1 + level_size;
	int			i;

	i = 0;
	while (idx + i < start_idx && map->values[idx + i] < 6)
		i++;
	if (idx + i == start_idx)
		return ;
	map->size += level_size;
	i = 0;
	while (idx + i < start_idx)
	{
		map->values[start_idx + i] = map->values[idx + i] / 3;
		map->values[mid_idx - i] = \
			map->values[idx + i] - 2 * (map->values[idx + i] / 3);
		map->values[end_idx - i] = map->values[idx + i] / 3;
		map->shapes[start_idx + i] = map->shapes[idx + i];
		map->shapes[mid_idx - i] = (map->shapes[idx + i] + 1) % 2;
		map->shapes[end_idx - i] = (map->shapes[idx + i] + 1) % 2;
		i++;
	}
	triangle_map_fill(map, start_idx);
}

void	triangle_map_show(const t_triangle_map *map, int cur_depth, int idx)
{
	int	i;

	if (cur_depth > map->depth)
		return ;
	i = -1;
	while (++i < cur_depth)
		printf("    ");
	if (cur_depth > 0)
		printf("+--");
	if (map->shapes[idx] == UP)
		printf("%d(%dU)\n", map->values[idx], cur_depth);
	else
		printf("%d(%dD)\n", map->values[idx], cur_depth);
	triangle_map_show(map, cur_depth + 1, 3 * idx + 1);
	triangle_map_show(map, cur_depth + 1, 3 * idx + 2);
	triangle_map_show(map, cur_depth + 1, 3 * idx + 3);
}

void	triangle_map_destroy(t_triangle_map *map)
{
	free(map->values);
	free(map->shapes);
	free(map);
}

int	triangle_map_get_depth(int size)
{
	int	depth;

	depth = 0;
	while (size >= 6)
	{
		size = size - 2 * (size / 3);
		depth++;
	}
	return (depth);
}

int	main(int argc, char **argv)
{
	const t_triangle_map	*map = triangle_map_create(atoi(argv[1]));
	argc = 0;
	triangle_map_show(map, 0, 0);
}
