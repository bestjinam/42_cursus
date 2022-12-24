#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include "../libft/libft/libft.h"
#include <signal.h>

void	get_readline(char **str, char *prompt)
{
	*str = readline(prompt);
	if (*str && **str)
		add_history(*str);
}

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("",0);

	}
	else if (signo == SIGQUIT)
		rl_on_new_line();
	rl_redisplay();

}

void	_env_signal_setting()
{
	struct termios	term;

	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
int main(void)
{
	char *res;

	_env_signal_setting();
	while(1)
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
