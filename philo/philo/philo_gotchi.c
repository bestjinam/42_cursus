/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:00:49 by jinam             #+#    #+#             */
/*   Updated: 2023/02/07 18:22:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include <unistd.h>

void	*philo_gotchi(void *raw)
{
	t_philo_info	*philo;

	philo = (t_philo_info *) raw;
	while (1)
	{
		pthread_mutex_lock(&philo->args->active_mx);
		if (philo->args->active == DEAD)
		{
			pthread_mutex_unlock(&philo->args->active_mx);
			break ;
		}
		pthread_mutex_unlock(&philo->args->active_mx);
		if (philo_eating(philo) == DEAD)
			break ;
		ft_usleep(philo->args->argv[3]);
	}
	return (NULL);
}
