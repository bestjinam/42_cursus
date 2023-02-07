/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:03:50 by jinam             #+#    #+#             */
/*   Updated: 2023/02/06 17:48:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		g_h;
int		g_w;
char	g_bg;
char	**g_tab;

typedef struct s_draw
{
	char	r;
	float	x;
	float	y;
	float	x2;
	float	y2;
	float	w;
	float	h;
	char	c;
}	t_draw;

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

int	is_in_rect(int x, int y, t_draw *el)
{
	return ((x - el->x < 1.0f) || (el->x2 - x < 1.0f) \
			|| (y - el->y < 1.0f) || (el->y2 - y < 1.0f));
}

void	_tab_printf(void)
{
	int	i;

	i = 0;
	while (g_tab[i])
	{
		ft_putstr(g_tab[i]);
		ft_putstr("\n");
		free(g_tab[i]);
		i ++;
	}
}

int	table_printf(FILE *fd, int err)
{
	if (err == 1)
		ft_putstr("Error: argument\n");
	else if (err == 2)
		ft_putstr("Error: Operation file corrupted\n");
	else
		_tab_printf();
	if (fd)
		fclose(fd);
	return (err);
}

int	_validate_input(FILE *fd, int res)
{
	if (!fd || res != 3)
		return (0);
	return (g_w > 0 && g_w <= 300 && g_h > 0 && g_h <= 300);
}

void	write_table(FILE *fd, t_draw *el)
{
	int	line;
	int	col;

	el->x2 = el->x + el->w;
	el->y2 = el->y + el->h;
	line = 0;
	while (line < g_h)
	{
		col = 0;
		while (col < g_w)
		{
			if (line >= el->y && el->y2 >= line && el->x <= col && col <= el->x2)
			{
				if (el->r == 'R' || (el->r == 'r' && is_in_rect(col, line, el)))
					g_tab[line][col] = el->c;
			}
			col ++;
		}
		line ++;
	}
}
	
int	main(int ac, char **av)
{
	FILE	*fd;
	int		res;
	int		i; 
	t_draw	el;
	
	fd = NULL;
	if (ac != 2)
		return (table_printf(fd, 1));
	fd = fopen(av[1], "r");
	res = fscanf(fd, "%d %d %c", &g_w, &g_h, &g_bg);
	if (_validate_input(fd, res))
	{
		g_tab = malloc(sizeof(char *) * (g_w + 1));
		g_tab[g_w] = 0;
		i = 0;
		while (i < g_h)
		{
			g_tab[i] = malloc((g_w + 1) * sizeof(char));
			g_tab[i][g_w] = 0;
			memset(g_tab[i], g_bg, g_w);
			i ++;
		}
		while (1)
		{
			res = fscanf(fd, "\n%c %f %f %f %f %c", &el.r, &el.x, &el.y, &el.w, &el.h, &el.c);
			if (res == EOF)
				return (table_printf(fd, 0));
			else if (res != 6 || el.w <= 0 || el.h <= 0 || (el.r != 'r' && el.r != 'R'))
				break ;
			write_table(fd, &el);
		}
	}
	table_printf(fd, 2);
}
