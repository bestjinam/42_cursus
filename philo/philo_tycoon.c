/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tycoon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:37:08 by jinam             #+#    #+#             */
/*   Updated: 2023/02/19 20:50:10 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	philo_dying(t_philo *victim)
{
	pthread_mutex_lock(&victim->watchdog->active_mt);
	victim->watchdog->active = DEAD;
	pthread_mutex_unlock(&victim->watchdog->active_mt);
	pthread_mutex_lock(&victim->speaker->print_mt);
	victim->speaker->print = UNAVAIL;
	printf("%d %d %s", philo_watch(victim->watchdog->start), victim->id, \
			"died\n");
	pthread_mutex_unlock(&victim->speaker->print_mt);
	return (DEAD);
}

int	philo_eating(t_philo *victim)
{
	struct timeval	start;

	if (preparing_forks(victim) == DEAD)
		return (DEAD);
	speaker_printf(victim, "is eating\n");
	updating_eat_time(victim);
	if (victim->args->argc == 5)
	{
		pthread_mutex_lock(&victim->eats_mt);
		if (victim->eats --)
			pthread_mutex_unlock(&victim->eats_mt);
		else
		{
			pthread_mutex_unlock(&victim->eats_mt);
			pthread_mutex_lock(&victim->watchdog->full_mt);
			victim->watchdog->full ++;
			pthread_mutex_unlock(&victim->watchdog->full_mt);
		}
	}
	gettimeofday(&start, NULL);
	ft_usleep(start, victim->args->eat_t);
	releasing_forks(victim);
	return (ALIVE);
}

int	philo_sleeping(t_philo *victim, int time)
{
	struct timeval	start;

	if (checking_vital(victim->watchdog) == DEAD)
		return (DEAD);
	speaker_printf(victim, "is sleeping\n");
	gettimeofday(&start, NULL);
	ft_usleep(start, time);
	return (ALIVE);
}

int	philo_thinking(t_philo *victim, int time)
{
	struct timeval	start;

	speaker_printf(victim, "is thinking\n");
	if (victim->args->num % 2 && time > 0)
	{
		gettimeofday(&start, NULL);
		ft_usleep(start, time);
	}
	else if (victim->args->num % 2 == 0 && victim-> id % 2)
		usleep(500);
	return (ALIVE);
}

void	*philo_tycoon(void *raw)
{
	t_philo	*victim;
	int		gap;

	victim = (t_philo *)raw;
	pthread_mutex_lock(&victim->watchdog->ready_mt);
	pthread_mutex_unlock(&victim->watchdog->ready_mt);
	if (victim->id % 2)
		usleep(800);
	while (1)
	{
		if (philo_eating(victim) != ALIVE)
			break ;
		if (victim->args->argc == 5 && checking_eat_time(victim) == COMPLETE)
			break ;
		if (philo_sleeping(victim, victim->args->sleep_t) != ALIVE)
			break ;
		gap = victim->args->eat_t * 2 - victim->args->sleep_t;
		if (philo_thinking(victim, gap) == DEAD)
			break ;
	}
	return (NULL);
}
