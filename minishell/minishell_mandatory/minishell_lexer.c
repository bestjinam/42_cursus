/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:27:15 by jinam             #+#    #+#             */
/*   Updated: 2022/12/27 17:17:25 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_mandatory.h"

static int	_make_type(char *str)
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

static ssize_t	_string_len(char *str)
{
	const size_t	str_len = ft_strlen(str);
	ssize_t			_len;
	size_t			i;

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
			return (-1);
		i ++;
	}
	_len += i;
	return (_len);
}

static ssize_t	_str_len(char *str, int type)
{
	const ssize_t	len[10] = {0, 1, 1, 2, 2, 1, 1, 1, 2, 2};

	if (type == STRING)
		return (_string_len(str));
	else
		return (len[type]);
}

static size_t	_pass_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i ++;
	return (i);
}

int	minishell_lexer(char *str, t_cmd_list *cmd_list)
{
	const size_t	str_len = ft_strlen(str);
	size_t			i;
	ssize_t			_len;
	int				type;

	i = 0;
	_len = 0;
	i += _pass_space(&str[i]);
	while (i < str_len)
	{
		type = _make_type(&str[i]);
		_len = _str_len(&str[i], type);
		if (_len == -1)
		{
			ft_error_msg("syntax_error");
			return (SYNTAX_ERROR);
		}
		cnode_add_back(cmd_list, cnode_new(ft_substr(str, i, _len), type));
		i += _len;
		i += _pass_space(&str[i]);
	}
	return (SUCCESS);
}
