/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tycoon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:33:29 by jinam             #+#    #+#             */
/*   Updated: 2023/02/10 18:54:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @brief init system_info(making philo and forks)
 * @param _sys [TODO:sys struct]
 * @param heads [TODO:numbers of philo]
 * @return [err : -1, success : 0]
 */
int	_organizing_table(t_system_info *_sys, int heads)
{
	int	i;

	_sys->args.active = LIVE;
	i = 0;
	_sys->philos = malloc(sizeof(t_philo_info) * (heads));
	_sys->forks = malloc(sizeof(t_fork) * (heads));
	if (!_sys->philos || !_sys->forks)
		return (-1);
	while (i < heads)
	{
		_sys->philos[i].last_eat = 0;
		_sys->philos[i].id = i + 1;
		_sys->forks[i].fork_st = AVAIL;
		pthread_mutex_init(&_sys->forks[i].fork_mt, NULL);
		_sys->philos[i].l_fork = &_sys->forks[i];
		_sys->philos[i].r_fork = &_sys->forks[(i + 1) % heads];
		_sys->philos[i].args = &_sys->args;
		_sys->philos[i].eats = 0;
		_sys->philos[i].philo_thread = NULL;
		pthread_mutex_init(&_sys->philos[i].leat_mx, NULL);
		pthread_mutex_init(&_sys->philos[i].eats_mx, NULL);
		i ++;
	}
	return (0);
}

int	_eating_monitoring(t_philo_info *philo)
{
	int	gap;

	gap = philo_timewatch(philo->args->start);
	pthread_mutex_lock(&philo->leat_mx);
	if (gap - philo->last_eat > philo->args->argv[1])
	{
		pthread_mutex_unlock(&philo->leat_mx);
		philo_dying(philo);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->leat_mx);
	return (LIVE);
}

void	_monitoring_table(t_system_info *_sys, int heads)
{
	int	i;
	int	cnt;

	while (_sys->args.active != DEAD)
	{
		usleep(200);
		cnt = 0;
		i = 0;
		while (i < heads)
		{
			if (_sys->args.argc == 5)
			{
				if (checking_eats(&_sys->philos[i]))
					cnt ++;
				else if (_eating_monitoring(&_sys->philos[i]) == DEAD)
					return ;
				if (cnt == heads)
					return ;
			}
			else
				if (_eating_monitoring(&_sys->philos[i]) == DEAD)
					return ;
			i ++;
		}
	}
}

int	_activating_table(t_system_info *_sys, int heads)
{
	int		i;
	void	*ret_val;

	i = 0;
	while (i < heads)
	{
		pthread_create(&_sys->philos[i].philo_thread, NULL, \
				philo_gotchi, &_sys->philos[i]);
		i ++;
	}
	if (gettimeofday(&_sys->args.start, NULL) == -1)
		return (-1);
	pthread_mutex_unlock(&_sys->args.ready_mx);
	_monitoring_table(_sys, heads);
	i = 0;
	while (i < heads)
	{
		pthread_join(_sys->philos[i].philo_thread, &ret_val);
		if (ret_val == PTHREAD_CANCELED)
			return (-1);
		i ++;
	}
	return (0);
}

int	run_philo_tycoon(t_system_info *_sys)
{
	int	res;

	res = _organizing_table(_sys, _sys->args.argv[0]);
	if (res == -1)
		return (-1);
	res = _activating_table(_sys, _sys->args.argv[0]);
	return (0);
}
