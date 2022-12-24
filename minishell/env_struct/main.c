#include <stdio.h>
#include "env_list.h"
#include <stdlib.h>

void	_env_print(t_env_node *nodes)
{
	while (nodes)
	{
		printf("name : %s | val : %s\n", nodes->name, nodes->val);
		nodes = nodes->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_env_list	env;
	t_env_node	*curr;
	t_env_node	*find;
	char		**str;
	int 		i;

	i = 0;
	env.head = NULL;
	env.len = 0;
	while (envp[i])
	{
		enode_add_back(&env, enode_new(envp[i]));
		i ++;
	}
	i = 0;
	_env_print(env.head);
	find = enode_find(&env, "PATH");
	str = enode_convert_char(&env);
	while (i < env.len)
	{
		printf("%s\n", str[i]);
		i ++;
	}
}
