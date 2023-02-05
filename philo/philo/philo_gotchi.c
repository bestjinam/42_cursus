/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:00:49 by jinam             #+#    #+#             */
/*   Updated: 2023/02/04 19:00:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	_philo_having_forks(t_philo_info *philo)
{
}

int	_philo_eating(t_philo_info *philo)
{
	int	ret;

	philo_printf(philo, "is eating\n");
	philo->eats ++;
	gettimeofday(&philo->last_eat, NULL);
	ret = LIVE;
	pthread_mutex_lock(&philo->args->active_mx);
	if (!philo->args->active)
		ret = DEAD;
	pthread_mutex_unlock(&philo->args->active_mx);
	return (ret);
}

void	*philo_gotchi(void *raw)
{
	t_philo_info	*philo;

	philo = (t_philo_info *) raw;
	while (1)
	{
		pthread_mutex_lock(&philo->args->active_mx);
		if (!philo->args->active)
		{
			pthread_mutex_unlock(&philo->args->active_mx);
			break ;
		}
		pthread_mutex_unlock(&philo->args->active_mx);
		if (_philo_eating(philo) == DEAD)
			break ;
	}
	return (NULL);
}
