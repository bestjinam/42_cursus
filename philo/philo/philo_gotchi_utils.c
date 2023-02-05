/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:08:06 by jinam             #+#    #+#             */
/*   Updated: 2023/02/05 21:11:54 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int	philo_timewatch(struct timeval *last)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - last->tv_sec) * 1000 \
			+ ((curr.tv_usec / 1000 - last->tv_usec / 1000)));
}

void	ft_usleep(int ms)
{
	struct timeval	start;
	int				gap;

	gettimeofday(&start, NULL);
	usleep(ms * 800);
	while (1)
	{
		gap = philo_timewatch(&start);
		if (gap >= ms)
			return ;
		usleep(200);
	}
}

void	philo_printf(t_philo_info *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print_mx);
	printf("%d %d %s", philo_timewatch(&philo->args->start), philo->id, str);
	pthread_mutex_unlock(&philo->args->print_mx);
}

int	philo_dying(t_philo_info *philo)
{
	philo_printf(philo, "died\n");
	pthread_mutex_lock(&philo->args->active_mx);
	philo->args->active = DEAD;
	pthread_mutex_unlock(&philo->args->active_mx);
	return (DEAD);
}
