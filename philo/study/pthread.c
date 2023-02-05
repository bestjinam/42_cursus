#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void	*test(void *data)
{
	int	i;
	int	a = *(int *) data;
	
	i = 0;
	while (i < 10)
	{
		printf("%d\n", i * a);
		i ++;
	}
	return ((void *)(i * 100));
}

int	main(void)
{
	int	a;
	pthread_t	thread_t;
	int			ret_code;
	int			status;

	ret_code = pthread_create(&thread_t, NULL, test, (void *)&a);
	if (ret_code < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	pthread_join(thread_t, (void **)&status);
	printf("Thread End %d\n", status);
	return (1);
}
