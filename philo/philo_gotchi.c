/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:38:53 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 18:14:10 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "philo.h"
#include <unistd.h>

int	philo_sleeping(t_philo *victim, int time)
{
	struct timeval	start;

	pthread_mutex_lock(&victim->jigsaw->active_mt);
	if (victim->jigsaw->active == DEAD)
	{
		pthread_mutex_unlock(&victim->jigsaw->active_mt);
		return (DEAD);
	}
	pthread_mutex_unlock(&victim->jigsaw->active_mt);
	jigsaw_printf(victim->id, victim->jigsaw, "is sleeping\n");
	gettimeofday(&start, NULL);
	ft_usleep(start, time);
	return (ALIVE);
}

int	philo_thinking(t_philo *victim, int time)
{
	struct timeval	start;

	jigsaw_printf(victim->id, victim->jigsaw, "is thinking\n");
	if (victim->id % 2)
	{
		if (time > 0)
		{
			gettimeofday(&start, NULL);
			ft_usleep(start, time);
		}
		else
			usleep(500);
	}
	return (ALIVE);
}

int	philo_eating(t_philo *victim)

{
	struct timeval	start;

	if (preparing_forks(victim) == DEAD)
		return (DEAD);
	jigsaw_printf(victim->id, victim->jigsaw, "is eating\n");
	pthread_mutex_lock(&victim->last_mt);
	victim->last_eat = jigsaw_watch(victim->jigsaw->start);
	pthread_mutex_unlock(&victim->last_mt);
	if (victim->args->argc == 5)
	{
		pthread_mutex_lock(&victim->eats_mt);
		if (--victim->eats == 0)
		{
			pthread_mutex_lock(&victim->jigsaw->full_mt);
			victim->jigsaw->full ++;
			pthread_mutex_unlock(&victim->jigsaw->full_mt);
		}
		pthread_mutex_lock(&victim->eats_mt);
	}
	gettimeofday(&start, NULL);
	ft_usleep(start, victim->args->eat);
	releasing_forks(victim);
	return (ALIVE);
}

int	philo_dying(t_philo *victim)
{
	pthread_mutex_lock(&victim->jigsaw->active_mt);
	victim->jigsaw->active = DEAD;
	pthread_mutex_unlock(&victim->jigsaw->active_mt);
	pthread_mutex_lock(&victim->jigsaw->print_mt);
	victim->jigsaw->print = UNAVAIL;
	printf("%d %d %s", jigsaw_watch(victim->jigsaw->start), \
			victim->id, "died\n");
	pthread_mutex_unlock(&victim->jigsaw->print_mt);
	return (DEAD);
}

// a(micro) = 500;
// eat_time 200 sleep 60 die 400 -> 홀 : 140 + a
// eat_time 200 sleep 200 die 400 -> 홀 : a  

void	*philo_gotchi(void *raw)
{
	t_philo	*victim;
	int		gap;

	victim = (t_philo *)raw;
	pthread_mutex_lock(&victim->jigsaw->ready_mt);
	pthread_mutex_unlock(&victim->jigsaw->ready_mt);
	if (victim->id % 2)
		usleep(800);
	while (1)
	{
		if (philo_eating(victim) != ALIVE)
		{
			printf("dajksdlaskd\n");
			break ;
		}
		if (victim->args->argc == 5 && victim->eats == 0)
			break ;
		if (philo_sleeping(victim, victim->args->sleep) == DEAD)
			break ;
		gap = victim->args->eat - victim->args->sleep;
		if (philo_thinking(victim, gap) == DEAD)
			break ;
	}
	return (NULL);
}
