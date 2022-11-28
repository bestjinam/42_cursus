/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:33:21 by jinam             #+#    #+#             */
/*   Updated: 2022/11/25 19:22:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx_test.h"
#include <stdio.h>
#include <stdlib.h>

void	window_init(t_mlx_instance *win)
{
	win->mlx_instance = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_instance, 800, 800, "ex01");
}

void	point_init(t_point *point)
{
	point->x = 0;
	point->y = 0;
}

int	key_press_0(int keycode, t_point *point)
{
	if (keycode == KEY_W)
		point->y += 1;
	else if (keycode == KEY_S)
		point->y -= 1;
	else if (keycode == KEY_A)
		point->x -= 1;
	else if (keycode == KEY_D)
		point->x += 1;
	else if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	printf("Current Position : (%ld, %ld)\n", point->x, point->y);
	return (0);
}

int	key_press_1(int keycode, t_point *point)
{
	static int	a;
	
	if (keycode == KEY_W)
		printf("UP\n");
	else if (keycode == KEY_S)
		printf("DOWN\n");
	else if (keycode == KEY_A)
		printf("LEFT\n");
	else if (keycode == KEY_D)
		printf("RIGHT\n");
	else
		return (0);
	return (0);
}

int	main(void)
{
	t_mlx_instance	win;
	t_data			info;
	t_point			point;

	window_init(&win);
	point_init(&point);
	printf("Current Position : (%ld, %ld)\n", point.x, point.y);
	//mlx_hook(win.mlx_win, X_EVENT_KEY_PRESS, 0, &key_press_1, &point);
	mlx_hook(win.mlx_win, X_EVENT_KEY_PRESS, 0, &key_press_0, &point);
	mlx_loop(win.mlx_instance);
	return (0);
}
