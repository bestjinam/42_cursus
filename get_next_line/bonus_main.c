#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		line_num = 1;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%d | %s", line_num++, str);
		free(str);
	}
	close(fd);
}
