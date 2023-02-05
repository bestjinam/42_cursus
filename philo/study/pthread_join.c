/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:21:17 by jinam             #+#    #+#             */
/*   Updated: 2023/02/01 15:40:30 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

# ifndef	NUM_THREADS
# define 	NUM_THREADS 8
# endif

void	*printHello(void *threadid)
{
	long	tid;

	tid = (long) threadid;
	printf("Hello from thread %ld %lu\n", tid, pthread_self());
	return (NULL);
}

int	main(int argc, char const *argv[])
{
	pthread_t	threads[NUM_THREADS];
	int			rc;
	long		t;
	int			ret;
	void		*retval;

	t = 0;
	while (t < NUM_THREADS)
	{
		rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
		if (rc)
		{
			printf("ERROR: return code from pthread_create() is %d\n", rc);
			exit(EXIT_FAILURE);
		}
		t ++;
	}
	t = 0;
	while (t < NUM_THREADS)
	{
		ret = pthread_join(threads[t], &retval);
		if (retval == PTHREAD_CANCELED)
			printf("The thread was canceled - \n");
		else 
			printf("Returned value %d - \n", (int)retval);
		t ++;
	}
	pthread_exit(NULL);
}
