/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_get_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:06:18 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 17:59:10 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_bonus.h"

t_stack	*get_cur_stk(t_stacks *stks, int opt)
{
	if (opt == 0)
		return (&stks->stk_a);
	else
		return (&stks->stk_b);
}

t_stack	*get_opposit_stk(t_stacks *stks, int opt)
{
	if (opt == 0)
		return (&stks->stk_b);
	else
		return (&stks->stk_a);
}
