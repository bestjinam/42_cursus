/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_get_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:06:18 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 21:52:46 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

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
