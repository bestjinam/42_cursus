/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:47:48 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 16:23:07 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
/*
<, <<, >,>> &&, || | (, )
	STRING
	"", ''

		STRING,
	RE_IN,
	RE_OUT,
	RE_APPEND,
	RE_HEREDOC,
	PIPE,
	BR_OPEN,
	BR_CLOSE,
	AND,
	OR
	*/

int	_make_type(char *str)
{
	int			i;
	const int	show_type[10] = {1, \
				ft_strncmp("<", str, 1) == 0, ft_strncmp(">", str, 1) == 0, \
				ft_strncmp(">>", str, 2) == 0, ft_strncmp("<<", str, 2) == 0, \
				ft_strncmp("|", str, 1) == 0, ft_strncmp("(", str, 1) == 0, \
				ft_strncmp(")", str, 1) == 0, ft_strncmp("&&", str, 2) == 0, \
				ft_strncmp("||", str, 2) == 0};
	i = 9;
	while (i >= 0)
	{
		if (show_type[i] == 1)
			return (i);
		i --;
	}
	return (i);
}

size_t	_meta_len(int type)
{
	size_t	len[10] = {0, 1, 1, 2, 2, 1, 1, 1, 2, 2};
	return (len[type]);
}

size_t	_string_len(char *str)
{
	size_t		str_len = ft_strlen(str);
	ssize_t		_len;
	size_t		i;

	_len = 0;
	
	i = _len;
	while (i < str_len)
	{
		if (ft_strchr("<>()|& ", str[i]))
			break ;
		if (*str == '\'')
			_len = ft_strchr(str + 1, '\'') - str;
		else if (*str == '\"')
			_len = ft_strchr(str + 1, '\"') - str;
		if (_len < 0)
		{
			printf("syntax error!\n");
			exit(1);
		}
		i ++;
	}
	_len += i;
	return (_len);
}

size_t	_pass_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i ++;
	return (i);
}

void	minishell_lexer(char *str, t_cmd_list *cmd_list)
{
	const size_t	str_len = ft_strlen(str);
	size_t			i;
	size_t			_str_len;
	int				type;

	i = 0;
	_str_len = 0;
	i += _pass_space(str);
	while (i < str_len)
	{
		type = _make_type(&str[i]);
		if (type != STRING)
		{
			_str_len = _meta_len(type);
		}
		else 
		{
			_str_len = _string_len(&str[i]);
		}
		cmd_node_add_back(cmd_list, \
				cmd_node_new(ft_substr(str, i, _str_len), type));
		i += _str_len;
		i += _pass_space(&str[i]);
	}
}
/*
int	main(void)
{
	t_cmd_node	*curr;
	t_cmd_list	cmd_list;
	cmd_list.head = NULL;
	cmd_list.len = 0;
	cmd_list.tail = NULL;
	minishell_lexer(">><<<kas'ddddddd'\"ddd\"dj||dkasjdklasjdklajsd", &cmd_list);
	curr = cmd_list.head;
	while (curr)
	{
		printf(">> %s\n", curr->data);
		curr = curr->next;
	}
} */
