/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:28:41 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 16:32:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_signal.h"
#include <unistd.h>
#include <readline/readline.h>

static void	_sig_handler(int signo)
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

void	env_signal_setting()
{
	struct termios	term;

	signal(SIGINT, _sig_handler);
	signal(SIGQUIT, _sig_handler);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

