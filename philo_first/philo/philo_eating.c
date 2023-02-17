/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:35:47 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 15:13:08 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include <unistd.h>

int	_grep_fork(t_philo_info *philo, t_args *args, t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&args->active_mx);
		if (args->active == DEAD)
		{
			pthread_mutex_unlock(&args->active_mx);
			return (DEAD);
		}
		pthread_mutex_unlock(&args->active_mx);
		pthread_mutex_lock(&fork->fork_mt);
		if (fork->fork_st == UNAVAIL)
			pthread_mutex_unlock(&fork->fork_mt);
		else
			break ;
	}
	fork->fork_st = UNAVAIL;
	pthread_mutex_unlock(&fork->fork_mt);
	philo_printf(philo, "has taken a fork\n");
	return (LIVE);
}

void	_ordering_forks(t_philo_info *philo, t_fork **first, t_fork **last)
{
	if (philo->id % 2)
	{
		*first = philo->r_fork;
		*last = philo->l_fork;
	}
	else
	{
		*first = philo->l_fork;
		*last = philo->r_fork;
	}
}

int	_preparing_forks(t_philo_info *philo)
{
	if (philo->id % 2)
	{
		if (_grep_fork(philo, philo->args, philo->l_fork) == DEAD)
			return (DEAD);
		if (_grep_fork(philo, philo->args, philo->r_fork) == DEAD)
			return (DEAD);
	}
	else
	{
		if (_grep_fork(philo, philo->args, philo->r_fork) == DEAD)
			return (DEAD);
		if (_grep_fork(philo, philo->args, philo->l_fork) == DEAD)
			return (DEAD);
	}
	return (LIVE);
}

void	_releasing_forks(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork_mt);
	philo->l_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&philo->l_fork->fork_mt);
	pthread_mutex_lock(&philo->r_fork->fork_mt);
	philo->r_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&philo->r_fork->fork_mt);
}

int	philo_eating(t_philo_info *philo)
{
	int				ret;
	struct timeval	start;

	if (_preparing_forks(philo) == DEAD)
		return (DEAD);
	philo_printf(philo, "is eating\n");
	pthread_mutex_lock(&philo->leat_mx);
	philo->last_eat = philo_timewatch(philo->args->start);
	pthread_mutex_unlock(&philo->leat_mx);
	pthread_mutex_lock(&philo->eats_mx);
	philo->eats ++;
	pthread_mutex_unlock(&philo->eats_mx);
	gettimeofday(&start, NULL);
	ft_usleep(start, philo->args->argv[2]);
	_releasing_forks(philo);
	ret = LIVE;
	return (ret);
}
