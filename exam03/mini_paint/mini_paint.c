/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:24:39 by jinam             #+#    #+#             */
/*   Updated: 2023/02/26 18:14:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_zone
{
	int		w;
	int		h;
	char	bg;
}	t_zone;

typedef struct s_draw
{
	char	c;
	float	x;
	float	y;
	float	r;
	char	ch;
}	t_draw;

t_zone	g_zone;
t_draw	g_draw;
char	**g_tab;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_exit(int err)
{
	int	i;

	if (g_tab)
	{
		i = -1;
		while (g_tab[++i])
			free(g_tab[i]);
		free(g_tab);
	}
	if (err != 0)
	{
		if (err == 1)
			ft_putstr("Error: argument\n");
		if (err == 2)
			ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	return (0);
}

int	init_zone(FILE *fp)
{
	if (fscanf(fp, "%d %d %c\n", &g_zone.w, &g_zone.h, &g_zone.bg) != 3)
		return (-1);
	if (g_zone.w <= 0 || g_zone.w > 300)
		return (-1);
	if (g_zone.h <= 0 || g_zone.h > 300)
		return (-1);
	return (0);
}

void	init_tab(void)
{
	int	i;

	g_tab = malloc(sizeof(char *) * (g_zone.h + 1));
	g_tab[g_zone.h] = 0;
	i = 0;
	while (i < g_zone.h)
	{
		g_tab[i] = malloc(sizeof(char) * (g_zone.w + 1));
		g_tab[i][g_zone.w] = 0;
		memset(g_tab[i], g_zone.bg, g_zone.w);
		i ++;
	}
}

int	is_it(float x, float y)
{
	float	res;

	res = sqrtf(powf(g_draw.x - x, 2.) + powf(g_draw.y - y, 2.));
	if (res <= g_draw.r)
	{
		if (g_draw.c == 'C')
			return (1);
		else if (g_draw.c == 'c' && g_draw.r - res < 1.)
			return (1);
	}
	return (0);
}

void	draw_shape(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < g_zone.h)
	{
		x = 0;
		while (x < g_zone.w)
		{
			if (is_it((float) x, (float) y) == 1)
				g_tab[y][x] = g_draw.ch;
			x ++;
		}
		y ++;
	}
}

int	read_shapes(FILE *fp)
{
	int	tmp;

	tmp = fscanf(fp, "%c %f %f %f %c\n", &g_draw.c, &g_draw.x, &g_draw.y, &g_draw.r, &g_draw.ch);
	while (tmp == 5)
	{
		if (g_draw.c != 'c' && g_draw.c != 'C')
			return (-1);
		if (g_draw.r <= 0)
			return (-1);
		draw_shape();
		tmp = fscanf(fp, "%c %f %f %f %c\n", &g_draw.c, &g_draw.x, &g_draw.y, &g_draw.r, &g_draw.ch);
	}
	if (tmp != EOF)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	FILE	*fp;
	int		i;

	if (ac != 2)
		return (ft_exit(1));
	fp = fopen(av[1], "r");
	if (!fp)
		return (ft_exit(2));
	if (init_zone(fp) == -1)
		return (ft_exit(2));
	init_tab();
	if (read_shapes(fp) == -1)
		return (ft_exit(2));
	i = -1;
	while (g_tab[++i])
	{
		ft_putstr(g_tab[i]);
		ft_putstr("\n");
	}
	return (ft_exit(0));
}
