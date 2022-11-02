/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:05:21 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 17:59:50 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_BONUS_H
# define OP_BONUS_H
# include "ds_bonus.h"
# include "../ft_utils/ft_printf/ft_printf.h"

enum e_op
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

/*operations*/
typedef void	(*t_op_ptr)(t_stacks *);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif
