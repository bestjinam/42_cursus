#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line_bonus.h"
#include <fcntl.h>

int init_log_file(const char *log_file)
{
	int	fd;

	fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND);
	if (fd == -1)
		return (0);
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	init_log_file("dup2_test.txt");
	if (argc < 2)
	{
		write(2, "input file error!\n", 18);
		return(1);
	}
	ft_printf("Hello World\n");
	return (0);
}
