#include "../libft/ft_printf/ft_printf.h"
#include "../libft/libft/libft.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_printf("%s <file1> <file2> ...", argv[0]);
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (access(argv[i], F_OK) < 0)
			ft_printf("file %s does not exist\n", argv[i]);
		else
		{
			if (access(argv[i], R_OK) == 0)
				ft_printf("You can read %s\n", argv[i]);
			if (access(argv[i], W_OK) == 0)
				ft_printf("You can write %s\n", argv[i]);
			if (access(argv[i], X_OK) == 0)
				ft_printf("You can execute %s\n", argv[i]);
		}
	}
	return (0);
}
