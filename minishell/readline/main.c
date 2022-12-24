#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft/libft.h"

int main(void)
{
	char	*res;

	while (1)
	{
		res = readline("minishell$");
		if (!res || ft_strncmp(res, "exit", 5) == 0)
		{
			if (!res)
				printf("\033[1A\033[10C exit");
			else
				printf("exit\n");
			free(res);
			break ;
		}
		printf("%s\n", res);
		free(res);
	}
	return (0);
}
