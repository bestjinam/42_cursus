/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:23:19 by jinam             #+#    #+#             */
/*   Updated: 2023/02/15 20:51:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

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

void	destroy_jigsaw(t_sys *_sys)
{
	pthread_mutex_destroy(&_sys->jigsaw.active_mt);
	pthread_mutex_destroy(&_sys->jigsaw.print_mt);
	pthread_mutex_destroy(&_sys->jigsaw.ready_mt);
	if (_sys->info.argc == 5)
		pthread_mutex_destroy(&_sys->jigsaw.full_mt);
	if (_sys->victims)
		free(_sys->victims);
	if (_sys->forks)
		free(_sys->forks);
}
