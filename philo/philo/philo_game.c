/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:48:25 by jinam             #+#    #+#             */
/*   Updated: 2023/02/20 18:20:24 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	_activating_victim(int i, t_philo *victim, t_room *room)
{
	victim->id = i + 1;
	victim->eats = 0;
	if (room->args.argc == 5)
		victim->eats = room->args.eat_cnt;
	victim->last_eat = 0;
	victim->l_fork = &room->forks[i];
	victim->r_fork = &room->forks[(i + 1) % room->args.num];
	if (pthread_mutex_init(&victim->last_mt, NULL) || \
			(victim->eats && pthread_mutex_init(&victim->eats_mt, NULL)) || \
			pthread_mutex_init(&victim->l_fork->fork_mt, NULL))
		return (MALLOC_FAIL);
	victim->watchdog = &room->watchdog;
	victim->speaker = &room->speaker;
	victim->args = &room->args;
	return (SUCCESS);
}

int	_organizing_table(t_room *room, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (_activating_victim(i, &room->victims[i], room) == MALLOC_FAIL)
			return (FAIL);
		pthread_create(&room->victims[i].philo, NULL, philo_tycoon, \
				&room->victims[i]);
		i ++;
	}
	if (gettimeofday(&room->watchdog.start, NULL) == -1)
		return (FAIL);
	return (SUCCESS);
}

int	_checking_victim(t_philo *victim)
{
	int	gap;

	pthread_mutex_lock(&victim->last_mt);
	gap = philo_watch(victim->watchdog->start) - victim->last_eat;
	pthread_mutex_unlock(&victim->last_mt);
	if (gap >= victim->args->die_t)
	{
		philo_dying(victim);
		return (DEAD);
	}
	return (ALIVE);
}

int	_run_monitor(t_room *room, int num)
{
	int	i;

	while (checking_vital(&room->watchdog) == ALIVE)
	{
		usleep(200);
		if (room->args.argc == 5)
		{
			pthread_mutex_lock(&room->watchdog.full_mt);
			if (room->watchdog.full == num)
				return (COMPLETE);
			pthread_mutex_unlock(&room->watchdog.full_mt);
		}
		i = 0;
		while (i < num)
		{
			if (_checking_victim(&room->victims[i]) == DEAD)
				return (DEAD);
			i ++;
		}
	}
	return (DEAD);
}

int	run_philo_game(t_room *room)
{
	int	res;
	int	i;

	pthread_mutex_lock(&room->watchdog.ready_mt);
	res = _organizing_table(room, room->args.num);
	if (res == FAIL)
		return (res);
	pthread_mutex_unlock(&room->watchdog.ready_mt);
	res = _run_monitor(room, room->args.num);
	if (res == COMPLETE)
		pthread_mutex_unlock(&room->watchdog.full_mt);
	i = 0;
	while (i < room->args.num)
	{
		pthread_join(room->victims[i].philo, NULL);
		i ++;
	}
	return (res);
}
