/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:01:44 by jinam             #+#    #+#             */
/*   Updated: 2023/02/12 20:15:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <string.h>
#include "philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	init_argvs(int argc, t_args *args, char **argv)
{
	int	i_idx;

	memset(args, 0, sizeof(t_args));
	pthread_mutex_init(&args->print_mx, NULL);
	pthread_mutex_init(&args->active_mx, NULL);
	pthread_mutex_init(&args->ready_mx, NULL);
	pthread_mutex_lock(&args->ready_mx);
	args->printable = AVAIL;
	args->argv = malloc(argc * sizeof(int));
	if (!args->argv)
		return (-1);
	i_idx = 0;
	while (argv[i_idx])
	{
		if (!str_is_digit(argv[i_idx]))
		{
			free(args->argv);
			return (-1);
		}
		args->argv[i_idx] = ft_atoi(argv[i_idx]);
		i_idx ++;
	}
	args->argc = argc - 1;
	return (0);
}

void	destroy_structs(t_system_info *_sys)
{
	int			i;
	const int	n = _sys->args.argv[0];

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&_sys->philos[i].leat_mx);
		pthread_mutex_destroy(&_sys->philos[i].eats_mx);
		pthread_mutex_destroy(&_sys->forks[i].fork_mt);
		i ++;
	}
	free(_sys->philos);
	free(_sys->forks);
	free(_sys->args.argv);
	pthread_mutex_destroy(&_sys->args.active_mx);
	pthread_mutex_destroy(&_sys->args.print_mx);
	pthread_mutex_destroy(&_sys->args.ready_mx);
}

//int	checking_argv(int len, )
int	main(int argc, char **argv)
{
	t_system_info	_sys;
	int				tmp;
	int				i;

	if (argc < 5 || argc > 6)
		return (philo_main_exit());
	tmp = init_argvs(argc, &_sys.args, &argv[1]);
	i = 0;
	while (i < argc - 1)
	{
		if (_sys.args.argv[i] < 0)
		{
			tmp = -1;
			break ;
		}
		i ++;
	}
	if (_sys.args.argv[0] == 0 || (argc == 6 && _sys.args.argv[4] == 0))
		tmp = -1;
	if (tmp != 0)
	{
		if (tmp == -1)
			write(2, "valid argument required\n", 27);
		else if (tmp == -2)
			write(2, "gettimeofday() call error\n", 26);
		return (philo_main_exit());
	}
	tmp = run_philo_tycoon(&_sys);
	destroy_structs(&_sys);
	return (0);
}
