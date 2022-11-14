#include <fcntl.h>
#include <unistd.h>
#include "../libft/get_next_line/get_next_line_bonus.h"
#include "../libft/ft_printf/ft_printf.h"

void open_and_read(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s", line);
	}
	close(fd);
}

void	create_and_write(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT, 0644);
	write(fd, "write something!\n",ft_strlen("write something!\n"));
	write(fd, "Can you duplicate it?\n",ft_strlen("Can you duplicate it?\n"));
	close(fd);
}

void	open_and_copy(char *src, char *dst)
{	
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open(src, O_RDONLY);
	fd2 = open(dst, O_WRONLY | O_CREAT, 0644);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		write(fd2, line, ft_strlen(line));
	}
	close(fd1);
	close(fd2);
}

void	open_and_dup(char *src, char *dst)
{
	int			fd1;
	int			fd2;
	const int	tmp_stdout = dup(STDOUT_FILENO);
	char		*line;

	fd1 = open(src, O_RDONLY);
	fd2 = open(dst, O_WRONLY | O_CREAT, 0644);
	dup2(fd2, 1);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		ft_printf("%s", line);
	}
	ft_printf("inserting a new line in the new file.\n");
	dup2(tmp_stdout, 1);
	ft_printf("하하 표준출력이지롱 메롱\n");
}

int	main(void)
{
	open_and_read("a_text_file.txt");
	create_and_write("new_file.txt");
	open_and_copy("new_file.txt", "dup_file.txt");
	open_and_dup("new_file.txt", "dup_file2.txt");
}
