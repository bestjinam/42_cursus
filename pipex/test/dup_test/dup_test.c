#include "../libft/get_next_line/get_next_line_bonus.h"
#include "../libft/ft_printf/ft_printf.h"
#include <fcntl.h>

int	main(void)
{
	int fd1;
	int	fd2;

	fd1 = open("test_fd.txt", O_RDONLY);
	fd2 = dup(fd1);
	ft_printf("fd1 : %d, fd2 : %d\n", fd1, fd2);
	ft_printf("fd1 : %s\n", get_next_line(fd1));
	ft_printf("fd2 : %s\n", get_next_line(fd2));
	close(fd1);
	close(fd2);
}
