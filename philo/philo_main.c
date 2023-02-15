/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:21:01 by jinam             #+#    #+#             */
/*   Updated: 2023/02/15 20:49:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	_init_argvs(int argc, t_args *args, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (FEW_ARGS);
	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[i]) || ft_atoi(argv[i]) < 0)
			return (INVALID);
		i ++;
	}
	args->argc = argc - 1;
	args->num = ft_atoi(argv[1]);
	args->die = ft_atoi(argv[2]);
	args->eat = ft_atoi(argv[3]);
	args->sleep = ft_atoi(argv[4]);
	args->eat_cnt = 0;
	if (argc == 6)
		args->eat_cnt = ft_atoi(argv[5]);
	if (args->num == 0 || (argc == 6 && args->eat_cnt == 0))
		return (ZERO);
	return (SUCCESS);
}

int	_init_jigsaw(t_sys *sys)
{
	if (pthread_mutex_init(&sys->jigsaw.active_mt, NULL) || \
	pthread_mutex_init(&sys->jigsaw.print_mt, NULL) || \
	pthread_mutex_init(&sys->jigsaw.ready_mt, NULL))
		return (MALLOC_FAIL);
	sys->jigsaw.print = AVAIL;
	sys->jigsaw.active = ALIVE;
	if (sys->info.argc == 5)
	{
		sys->jigsaw.full = 0;
		if (pthread_mutex_init(&sys->jigsaw.full_mt, NULL))
			return (MALLOC_FAIL);
	}
	return (SUCCESS);
}

int	_init_room(int argc, char **argv, t_sys *_sys)
{
	int	tmp;

	memset(_sys, 0, sizeof(t_sys));
	tmp = _init_argvs(argc, &_sys->info, &argv[0]);
	if (tmp != SUCCESS)
	{
		if (tmp == FEW_ARGS)
			return (philo_err_exit());
		else if (tmp == INVALID)
			ft_putstr(2, "valid argument required\n");
		return (tmp);
	}
	tmp = _init_jigsaw(_sys);
	if (tmp == MALLOC_FAIL)
	{
		destroy_jigsaw(_sys);
		return (tmp);
	}
	_sys->victims = malloc(sizeof(t_philo) * _sys->info.num);
	_sys->forks = malloc(sizeof(t_fork) * _sys->info.num);
	if (!_sys->victims || !_sys->forks)
		return (MALLOC_FAIL);
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_sys	_sys;
	int		tmp;

	tmp = _init_room(argc, argv, &_sys);
	if (tmp != SUCCESS)
		return (1);
	tmp = run_philo_game(&_sys);
}
