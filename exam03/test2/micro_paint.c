/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:53:12 by jinam             #+#    #+#             */
/*   Updated: 2023/02/13 21:57:27 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

t_args	g_args;
t_draw	g_draw;
char	g_grid[10000][10000];

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

int	is_in_rect(int x, int y)
{
	return ((x - g_draw.x < 1.0f) || (g_draw.x2 - x < 1.0f) \
			|| ((y - g_draw.y < 1.0f) || (g_draw.y2 - y < 1.0f)));
}

void	_tab_printf(void)
{
	int	i;

	i = 0;
	while (g_args.tab[i])
	{
		ft_putstr(g_args.tab[i]);
		ft_putstr("\n");
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
	return (g_args.w > 0 && g_args.w <= 300 && g_args.h > 0 && g_args.h <= 300);
}

void	write_table(FILE *fd)
{
	int	line;
	int	col;

	g_draw.x2 = g_draw.x + g_draw.w;
	g_draw.y2 = g_draw.y + g_draw.h;
	line = 0;
	while (line < g_args.w)
	{
		col = 0;
		while (col < g_args.h)
		{
			if (g_draw.y <= line && line <= g_draw.y2 && g_draw.x <= col && col <= g_draw.x2)
			{
				if (g_draw.r == 'R' || (g_draw.r == 'r' && is_in_rect(col, line)))
					g_args.tab[line][col] = g_draw.c;
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

	fd = NULL;
	if (ac != 2)
		return (table_printf(fd, 1));
	fd = fopen(av[1], "r");
	res = fscanf(fd, "%d %d %c", &g_args.w, &g_args.h, &g_args.bg);
	if (_validate_input(fd, res))
	{
		g_args.tab = malloc(sizeof(char *) * (g_args.h + 1));
		g_args.tab[g_args.h] = 0;
		i = 0;
		while (i < g_args.h)
		{
			g_args.tab[i] = malloc(sizeof(char) * (g_args.w + 1));
			g_args.tab[i][g_args.w] = 0;
			memset(g_args.tab[i], g_args.bg, g_args.w);
			i ++;
		}
		while (1)
		{
			res = fscanf(fd, "\n%c %f %f %f %f %c", &g_draw.r, &g_draw.x, &g_draw.y, &g_draw.w, &g_draw.h, &g_draw.c);
			if (res == EOF)
				return (table_printf(fd, 0));
			if (res != 6 || g_draw.w <= 0 || g_draw.h <= 0 || (g_draw.r != 'r') && (g_draw.r != 'R'))
				break ;
			write_table(fd);
		}
	}
	table_printf(fd, 2);
}
