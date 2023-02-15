/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tycoon_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:52:52 by jinam             #+#    #+#             */
/*   Updated: 2023/02/10 18:53:25 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checking_eats(t_philo_info *philo)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philo->eats_mx);
	if (philo->eats >= philo->args->argv[4])
		res = 1;
	pthread_mutex_unlock(&philo->eats_mx);
	return (res);
}
