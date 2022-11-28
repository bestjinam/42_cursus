/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:20 by jinam             #+#    #+#             */
/*   Updated: 2022/11/25 19:06:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TEST_H
# define MLX_TEST_H

# include "../minilibx_mms_20200219/mlx.h"
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx_instance
{
	void	*mlx_instance;
	void	*mlx_win;
	int		size[2];
}	t_mlx_instance;

typedef struct s_point
{
	long	x;
	long	y;
}	t_point;

typedef enum e_keys
{
	KEY_ESC	= 53,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
}	t_keys;

#endif
