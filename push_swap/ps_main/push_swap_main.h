/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:43:02 by jinam             #+#    #+#             */
/*   Updated: 2022/11/02 13:16:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MAIN_H
# define PUSH_SWAP_MAIN_H

# include <unistd.h>
# include "../data_structure/data_structure.h"
# include "../triangle_map/triangle_map.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../ps_commands/op.h"
# include "../ps_sorting/push_swap_sorting.h"

int		is_sorting(int *arr, int *input, int size);
void	print_error(void);
int		pre_sorting_and_filtering(t_stacks *stacks);
int		conv_str_to_int(char **str, t_stacks *stacks);
int		read_argvs(int argc, char **argv, t_stacks *stacks);
void	init_stacks(t_stacks *stacks);
#endif
