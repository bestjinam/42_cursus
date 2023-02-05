/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:03:57 by jinam             #+#    #+#             */
/*   Updated: 2023/02/04 19:03:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	philo_timewatch(struct timeval *last)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - last->tv_sec) * 1000 \
			+ ((curr.tv_usec / 1000 - last->tv_usec / 1000)));
}

void	philo_printf(t_philo_info *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print_mx);
	printf("%d %d %s", philo_timewatch(&philo->args->start), philo->id, str);
	pthread_mutex_unlock(&philo->args->print_mx);
}

int	philo_dying(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->args->active_mx);
	philo_printf(philo, "died\n");
	philo->args->active = 0;
	pthread_mutex_unlock(&philo->args->active_mx);
	return (DEAD);
}
