/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:33:00 by jinam             #+#    #+#             */
/*   Updated: 2022/11/28 21:45:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCTURE_H
# define FRACTOL_STRUCTURE_H

typedef struct s_img
{
	void	*img_ptr;
	void	*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win;
	int				size[2];
	struct s_img	img;
	int				type;
}	t_mlx;

enum e_keycodes
{
	ESC = 53,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
};

enum e_event
{
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_EXIT = 17
};

typedef struct s_point
{
	long double	x;
	long double	y;
	long double	width;
	long double	height;
}	t_point;

#endif
