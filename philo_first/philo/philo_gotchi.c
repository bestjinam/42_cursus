/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:00:49 by jinam             #+#    #+#             */
/*   Updated: 2023/02/13 22:08:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include <unistd.h>

int	philo_sleeping(t_philo_info *philo, int time)
{
	struct timeval	start;

	pthread_mutex_lock(&philo->args->active_mx);
	if (philo->args->active == DEAD)
	{
		pthread_mutex_unlock(&philo->args->active_mx);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->args->active_mx);
	philo_printf(philo, "is sleeping\n");
	gettimeofday(&start, NULL),
	ft_usleep(start, time);
	return (LIVE);
}

int	philo_thinking(t_philo_info *philo, int time)
{
	philo_printf(philo, "is thinking\n");
	if (philo->id % 2)
		usleep(time);
	return (LIVE);
}

void	*philo_gotchi(void *raw)
{
	t_philo_info	*philo;

	philo = (t_philo_info *) raw;
	pthread_mutex_lock(&philo->args->ready_mx);
	pthread_mutex_unlock(&philo->args->ready_mx);
	if (philo->id % 2)
		usleep(800);
	while (1)
	{
		if (philo_eating(philo) == DEAD)
			break ;
		if (philo->args->argc == 5 && philo->args->argv[4] == philo->eats)
			break ;
		if (philo_sleeping(philo, philo->args->argv[3]) == DEAD)
			break ;
		if (philo_thinking(philo, 500) == DEAD)
			break ;
	}
	return (NULL);
}
