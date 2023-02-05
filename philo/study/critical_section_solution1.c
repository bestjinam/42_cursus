/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_section_solution1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:08 by jinam             #+#    #+#             */
/*   Updated: 2023/02/01 20:39:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*count(void *arg);
int	cnt = 0;

typedef struct s_val
{
	char	*name;
	pthread_mutex_t	*c_mutex;
}	t_val;

void	struct_init(pthread_mutex_t	*tmp, t_val *thread, char *name)
{
	thread->name = name;
	thread->c_mutex = tmp;
}

int	main(void)
{
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	tmp;
	t_val			value1;
	t_val			value2;

	// mutex 
	printf("asdf\n");
	pthread_mutex_init(&tmp, NULL);
	printf("2asdf\n");
	struct_init(&tmp, &value1, "thread1");
	printf("3asdf\n");
	struct_init(&tmp, &value2, "thread2");
	printf("4asdf\n");
	pthread_create(&thread1, NULL, count, (void *) &value1);
	printf("5asdf\n");
	pthread_create(&thread2, NULL, count, (void *) &value2);
	printf("6asdf\n");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}

void	*count(void *arg)
{
	int			i;
	const t_val *value = (const t_val *)arg;

	
	//CRITICAL_SECTION
	i = 0;
	while (i < 100)
	{
		pthread_mutex_lock(value->c_mutex);
		printf("%s cnt : %d\n", value->name, ++cnt);
		pthread_mutex_unlock(value->c_mutex);
		i ++;
	}
	//CRITICAL_SECTION
	return(NULL);
}
