#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft/libft.h"

void get_readline(char **str, char *prompt)
{
	*str = readline(prompt);
	if (*str && **str)
		add_history(*str);
}

int main(void)
{
	char	*res;

	while (1)
	{
		get_readline(&res, "minishell$ ");
		if (!res || ft_strncmp(res, "exit", 5) == 0)
		{
			if (!res)
				printf("\033[1A\033[%dCexit", (int)ft_strlen("minishell$ "));
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
