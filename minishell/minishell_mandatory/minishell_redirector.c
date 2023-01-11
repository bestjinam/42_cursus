/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:25:08 by jinam             #+#    #+#             */
/*   Updated: 2023/01/11 19:34:13 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "minishell_mandatory.h"

int	_confirm_fd(char *str1, int fd1, int fd2)
{
	if (fd1 < 0)
		perror(str1);
	else if (fd2 < 0)
		perror(str1);
	return (fd1 >= 0 && fd2 >= 0);
}


int	_access_data(void *raw)
{
	t_cmd_data	*data;
	int			read_fd;
	int			write_fd;

	data = raw;
	read_fd = 0;
	write_fd = 1;
	if (data->type == RE_HEREDOC)
		read_fd = (long) data->string;
	else if (data->type == RE_IN)
		read_fd = open(data->string, O_RDONLY);
	else if (data->type == RE_OUT)
		write_fd = open(data->string, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (data->type == RE_APPEND)
		write_fd = open(data->string, O_APPEND | O_CREAT, 0644);
	if (_confirm_fd(data->string, read_fd, write_fd) == 0)
		return (FILE_ERROR);
	dup2(read_fd, 0);
	dup2(write_fd, 1);
	if (read_fd != STDIN_FILENO)
		close(read_fd);
	if (write_fd != STDOUT_FILENO)
		close(write_fd);
	return (SUCCESS);
}

int	minishell_redirector(t_list *head)
{
	t_list	*curr;
	int		res;

	curr = head;
	while (curr)
	{
		res = _access_data(curr->content);
		if (res == FILE_ERROR)
			return (res);
		curr = curr->next;
	}
	return (SUCCESS);
}
