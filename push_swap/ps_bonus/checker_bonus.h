/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:43:02 by jinam             #+#    #+#             */
/*   Updated: 2022/11/02 13:18:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include "ds_bonus.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "op_bonus.h"

void	print_error(void);
int		pre_sorting_and_filtering(t_stacks *stacks);
int		conv_str_to_int(char **str, t_stacks *stacks);
int		read_argvs(int argc, char **argv, t_stacks *stacks);
void	init_stacks(t_stacks *stacks);
void	merge_sort(int left, int right, t_stacks *stacks);
#endif
