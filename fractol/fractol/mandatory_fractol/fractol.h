/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:31:23 by jinam             #+#    #+#             */
/*   Updated: 2022/11/30 15:15:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "fractol_structure.h"
# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

# define VIEW 800

typedef void	(*t_fractol_funcptr)(t_mlx *);

unsigned int	mb_get_color(int *xy, t_point *point, int line_len, int c);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color(int iter, int cnt);

void			draw_mandelbrot(t_mlx *mlx);
void			draw_julia(t_mlx *mlx);
unsigned int	j_get_color(int *xy, t_point *point, int line_len, int c);

int				mouse_event(int button, int x, int y, t_mlx *mlx);
int				key_event(int keycode, t_mlx *mlx);
#endif
