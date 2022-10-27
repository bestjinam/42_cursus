/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:35 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 16:13:54 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAP_H
# define TRIANGLE_MAP_H

# include <stdlib.h>
# define UP 0
# define DOWN 1

typedef struct s_triangle_map
{
	int		*values;
	char	*shapes;
	int		size;
	int		depth;
}	t_triangle_map;

t_triangle_map	*triangle_map_create(int input_size);
void			triangle_map_destroy(t_triangle_map *map);
void			calculate_idx_and_size(int depth, int *m_idx, int *size);
int				calculate_depth(int size);
void	triangle_map_show(const t_triangle_map *map, int cur_depth, int idx);
#endif
