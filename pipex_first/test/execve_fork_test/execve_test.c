#include "../libft/ft_printf/ft_printf.h"
#include "../libft/libft/libft.h"


char	*make_whole_path(char *envpath, char *cmd)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(envpath, "/");
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	return (res);
}

char	**parsing_envp(char *envp[])
{
	char	**tmp;
	char	**res;
	int		i;

	i = -1;
	res = NULL;
	while (envp[++i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_split(envp[i], '=');
			res = ft_split(tmp[1], ':');
			free(tmp);
		}
	}
	return (res);
}

char *get_executables(char *cmd, char *paths[])
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (paths[++i])
	{
		cmd_path = make_whole_path(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
	}
	return (NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	char	**paths;
	char	*cmd_path;
	char	*args[2];

	if (argc < 2)
	{
		ft_printf("%s <cmd>", argv[0]);
		return (1);
	}
	paths = parsing_envp(envp);
	cmd_path = get_executables(argv[1], paths);	
	if (!cmd_path)
		return (1);
	args[0] = cmd_path;
	args[1] = NULL;
	execve(cmd_path, args, envp);
}
