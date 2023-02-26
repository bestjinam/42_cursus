/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tycoon_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:54:20 by jinam             #+#    #+#             */
/*   Updated: 2023/02/20 14:54:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	checking_eat_time(t_philo *victim)
{
	int	res;

	res = INCOMPLETE;
	pthread_mutex_lock(&victim->eats_mt);
	if (victim->eats == 0)
		res = COMPLETE;
	pthread_mutex_unlock(&victim->eats_mt);
	return (res);
}

void	updating_eat_time(t_philo *victim)
{
	pthread_mutex_lock(&victim->last_mt);
	victim->last_eat = philo_watch(victim->watchdog->start);
	pthread_mutex_unlock(&victim->last_mt);
}

int	_grep_fork(t_philo *victim, t_fork *fork)
{
	while (1)
	{
		if (checking_vital(victim->watchdog) == DEAD)
			return (DEAD);
		pthread_mutex_lock(&fork->fork_mt);
		if (fork->fork == UNAVAIL)
			pthread_mutex_unlock(&fork->fork_mt);
		else
			break ;
		usleep(200);
	}
	fork->fork = UNAVAIL;
	pthread_mutex_unlock(&fork->fork_mt);
	speaker_printf(victim, "has taken a fork\n");
	return (ALIVE);
}

void	releasing_forks(t_philo *victim)
{
	pthread_mutex_lock(&victim->l_fork->fork_mt);
	victim->l_fork->fork = AVAIL;
	pthread_mutex_unlock(&victim->l_fork->fork_mt);
	pthread_mutex_lock(&victim->r_fork->fork_mt);
	victim->r_fork->fork = AVAIL;
	pthread_mutex_unlock(&victim->r_fork->fork_mt);
}

int	preparing_forks(t_philo *victim)
{
	if (victim->id % 2)
	{
		if (_grep_fork(victim, victim->l_fork) == DEAD)
			return (DEAD);
		if (_grep_fork(victim, victim->r_fork) == DEAD)
			return (DEAD);
	}
	else
	{
		if (_grep_fork(victim, victim->r_fork) == DEAD)
			return (DEAD);
		if (_grep_fork(victim, victim->l_fork) == DEAD)
			return (DEAD);
	}
	return (ALIVE);
}
