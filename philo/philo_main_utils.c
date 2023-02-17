/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:19 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 13:39:04 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void	ft_usleep(struct timeval start, int ms)
{
	int	gap;

	usleep(ms * 800);
	while (1)
	{
		if (jigsaw_watch(start) >= ms)
			return ;
		usleep(200);
	}
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	write(fd, str, i);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	philo_err_exit(void)
{
	ft_putstr(2, "Usage: ./philo philos(n) die(ms) eat(ms) sleep(ms) ");
	ft_putstr(2, "[must eat]\n");
	return (FEW_ARGS);
}
