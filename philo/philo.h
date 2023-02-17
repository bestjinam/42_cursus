/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:36:58 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 18:08:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	argc;
	int	num;
	int	eat;
	int	die;
	int	sleep;
	int	eat_cnt;
}	t_args;

typedef struct s_sys_info
{
	struct timeval	start;
	int				active;
	int				print;
	int				full;
	pthread_mutex_t	full_mt;
	pthread_mutex_t	active_mt;
	pthread_mutex_t	ready_mt;
	pthread_mutex_t	print_mt;
}	t_sys_info;

typedef struct s_fork
{
	int				fork_st;
	pthread_mutex_t	fork_mt;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eats;
	int				last_eat;
	pthread_mutex_t	last_mt;
	pthread_mutex_t	eats_mt;
	pthread_t		philo;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_args			*args;
	t_sys_info		*jigsaw;
}	t_philo;

typedef struct s_sys
{
	t_args		info;
	t_sys_info	jigsaw;
	t_philo		*victims;
	t_fork		*forks;
}	t_sys;

enum e_status
{
	AVAIL,
	UNAVAIL,
	ALIVE,
	DEAD,
	FINISH,
};

enum e_err
{
	SUCCESS,
	FEW_ARGS,
	INVALID,
	ZERO,
	MALLOC_FAIL,
	FAIL,
};

void	ft_usleep(struct timeval start, int ms);
void	ft_putstr(int fd, char *str);
int		ft_isdigit(int c);
int		str_is_digit(char *str);
int		philo_err_exit(void);
void	destroy_jigsaw(t_sys *_sys);

int		ft_atoi(const char *str);

int		run_philo_game(t_sys *sys);

void	*philo_gotchi(void *raw);
int		philo_dying(t_philo *victim);

int		jigsaw_watch(struct timeval last);
void	jigsaw_printf(int id, t_sys_info *jigsaw, char *str);

int		preparing_forks(t_philo *victim);
void	releasing_forks(t_philo *victim);

#endif
