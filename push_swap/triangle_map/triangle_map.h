/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:35 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 15:45:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAP_H
# define TRIANGLE_MAP_H

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

enum e_mold_type
{
	UP = 0,
	DOWN = 1
};

typedef struct s_trg_map
{
	int			*val;
	char		*mold;
	int			size;
	int			depth;
}	t_triangle_map;

// triangle_map_generate
t_triangle_map	*trg_map_create(int size);
void			trg_map_destroy(t_triangle_map *map);

// triangle_map_show
void			trg_map_show_1(const t_triangle_map *m, int c_depth, int i);
void			trg_map_show_2(const t_triangle_map *map);

// triangle_map_utils
int				trg_map_get_level_start_idx(int depth);
void			calculate_idx_and_size(int depth, int *m_idx, int *size);
int				calculate_len(t_triangle_map *map, int m_idx, int size);
#endif
