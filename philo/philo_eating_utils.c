/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:32 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 18:15:03 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	_grep_fork(t_philo *victim, t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&victim->jigsaw->active_mt);
		if (victim->jigsaw->active == DEAD)
		{
			pthread_mutex_unlock(&victim->jigsaw->active_mt);
			return (DEAD);
		}
		pthread_mutex_unlock(&victim->jigsaw->active_mt);
		pthread_mutex_lock(&fork->fork_mt);
		if (fork->fork_st == UNAVAIL)
			pthread_mutex_unlock(&fork->fork_mt);
		else
			break ;
	}
	fork->fork_st = UNAVAIL;
	pthread_mutex_unlock(&fork->fork_mt);
	jigsaw_printf(victim->id, victim->jigsaw, "has taken a fork\n");
	return (ALIVE);
}

int	preparing_forks(t_philo *victim)
{
	if (victim->id % 2)
	{
		if (_grep_fork(victim, victim->l_fork) == DEAD)
			return (DEAD);
		printf("whdkllfjsdlkfjsld\n");
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

void	releasing_forks(t_philo *victim)
{
	pthread_mutex_lock(&victim->l_fork->fork_mt);
	victim->l_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&victim->l_fork->fork_mt);
	pthread_mutex_lock(&victim->r_fork->fork_mt);
	victim->r_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&victim->r_fork->fork_mt);
}
