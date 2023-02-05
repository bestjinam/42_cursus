/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:05:57 by jinam             #+#    #+#             */
/*   Updated: 2023/02/04 19:05:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	struct timeval	start;
	int				*argv;
	int				argc;
	int				active;
	pthread_mutex_t	active_mx;
	pthread_mutex_t	print_mx;
}	t_args;

typedef struct s_fork
{
	int				fork_st;
	pthread_mutex_t	fork_mt;
}	t_fork;

typedef struct s_philo_info
{
	int				id;
	int				eats;
	struct timeval	last_eat;
	pthread_t		philo_thread;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_args			*args;
}	t_philo_info;

typedef struct s_system_info
{
	t_args			args;
	t_philo_info	*philos;
	t_fork			*forks;
}	t_system_info;

enum	e_status_codes
{
	AVAIL,
	UNAVAIL,
	LIVE,
	DEAD,
	FULL
};
//philo_main_utils.c
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

//philo_error_utils.c
int		philo_main_exit(void);
int		_str_is_digit(char *str);

//philo_tycoon.c
int		run_philo_tycoon(t_system_info *_sys);

//philo_gotchi.c
void	*philo_gotchi(void *raw);

//philo_gotchi_utils.c
int		philo_dying(t_philo_info *philo);
int		philo_timewatch(struct timeval *last);
void	philo_printf(t_philo_info *philo, char *str);
#endif