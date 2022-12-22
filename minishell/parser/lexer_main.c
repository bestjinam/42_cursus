#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include "../libft/libft/libft.h"
#include <signal.h>
#include "lexer.h"
#include "parser.h"

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
	//signal(SIGQUIT, sig_handler);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	_show_cmd_list(t_cmd_node *curr)
{
	while (curr)
	{
		printf(">> %s\n", curr->data);
		curr = curr->next;
	}
}

void	__printf_contents(void *curr)
{
	printf("%s -> ", ((t_cmd_data *) curr)->string);
}

void	_show_cmd_tree(t_cmd_tnode *root)
{
	t_list *curr;

	if (!root)
		return ;
	curr = root->string;
	if (curr)
	{
		printf("%p\n", root);
		ft_lstiter(curr, __printf_contents);
	}
	else
		printf("*****************************%d",root->type);
	printf("\n");
	printf("#################################################\n");
	printf("%p %p \n", root->l_node, root->r_node);
	_show_cmd_tree(root->l_node);
	_show_cmd_tree(root->r_node);
}

int main(void)
{
	char *res;
	t_cmd_node	*curr;
	t_cmd_list	cmd_list;
	t_cmd_tree	cmd_tree;

	ft_memset(&cmd_list, 0, sizeof(cmd_list));
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
		if (!*res)
			continue ;
		minishell_lexer(res, &cmd_list);
		ft_memset(&cmd_tree, 0, sizeof(cmd_tree));
		if (parsing_process(&cmd_tree, &cmd_list) != 0)
			exit(1);
		printf("----------%d\n", cmd_tree.root->type);
		_show_cmd_tree(cmd_tree.root);
		while (cmd_list.len)
			cmd_node_delete(&cmd_list, cmd_list.head->data);
		free(res);
	}
	return (0);
}
