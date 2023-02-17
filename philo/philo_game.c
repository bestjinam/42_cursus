/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:58:31 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 17:39:45 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
/*
 	int				id;
	int				eats;
	int				last_eat;
	pthread_mutex_t	last_mt;
	pthread_mutex_t	eats_mt;
	pthread_t		philo;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_args			*args;
	t_sys_info		*info;
	*/
void	_activating_victim(int i, t_philo *victim, t_sys *sys)
{
	victim->id = i + 1;
	victim->eats = 0;
	if (sys->info.argc == 5)
		victim->eats = sys->info.eat_cnt;
	victim->last_eat = 0;
	pthread_mutex_init(&victim->last_mt, NULL);
	pthread_mutex_init(&victim->last_mt, NULL);
	victim->l_fork = &sys->forks[i];
	victim->r_fork = &sys->forks[(i + 1) % sys->info.num];
	pthread_mutex_init(&victim->l_fork->fork_mt, NULL);
	victim->jigsaw = &sys->jigsaw;
	victim->args = &sys->info;
}

int	_organizing_table(t_sys *sys, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		_activating_victim(i, &sys->victims[i], sys);
		pthread_create(&sys->victims[i].philo, NULL, \
				philo_gotchi, &sys->victims[i]);
		i ++;
	}
	if (gettimeofday(&sys->jigsaw.start, NULL) == -1)
		return (FAIL);
	return (SUCCESS);
}

int	_checking_victim(t_philo *victim)
{
	int	res;

	res = ALIVE;
	pthread_mutex_lock(&victim->eats_mt);
	if (victim->eats >= victim->args->die)
		res = DEAD;
	pthread_mutex_unlock(&victim->eats_mt);
	return (res);
}

int	_run_jigsaw(t_sys *sys, t_philo **victims, int num)
{
	int	i;

	while (sys->jigsaw.active != DEAD)
	{
		usleep(200);
		if (sys->info.argc == 5)
		{
			pthread_mutex_lock(&sys->jigsaw.full_mt);
			if (sys->jigsaw.full == num)
				return (FINISH);
			pthread_mutex_unlock(&sys->jigsaw.full_mt);
		}
		i = 0;
		while (i < num)
		{
			if (_checking_victim(victims[i]) == DEAD)
				return (DEAD);
			i ++;
		}
	}
	return (DEAD);
}

int	run_philo_game(t_sys *sys)
{
	int	res;
	int	i;

	pthread_mutex_lock(&sys->jigsaw.ready_mt);
	res = _organizing_table(sys, sys->info.num);
	if (res == FAIL)
		return (FAIL);
	pthread_mutex_unlock(&sys->jigsaw.ready_mt);
	res = _run_jigsaw(sys, &sys->victims, sys->info.num);
	if (res == FINISH)
		pthread_mutex_unlock(&sys->jigsaw.full_mt);
	i = 0;
	while (i < sys->info.num)
	{
		pthread_join(sys->victims[i].philo, NULL);
		i ++;
	}
	return (res);
}
