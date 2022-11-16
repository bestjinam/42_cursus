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

int	main(int argc, char **argv, char *envp[])
{
	int		i;
	int		j;
	char	**paths;
	char	*cmp_path;

	if (argc < 2)
	{
		ft_printf("%s <cmd> <cmd> ...", argv[0]);
		return (1);
	}
	paths = parsing_envp(envp);
	i = 0;
	while (argv[++i] != 0)
	{
		j = -1;
		while (paths[++j] != 0)
		{
			cmp_path = make_whole_path(paths[j], argv[i]);
			if (access(cmp_path, F_OK | X_OK) == 0)
			{
				ft_printf("cmd  %s exist and executable\n", argv[i]);
				break;
			}
		}
	}
	exit(0);
}
