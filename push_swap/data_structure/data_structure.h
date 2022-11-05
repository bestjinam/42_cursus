/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:12:08 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 15:06:59 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H
# include <unistd.h>

typedef struct s_stack
{
	int		*buffer;
	ssize_t	len;
	ssize_t	cap;
	ssize_t	front;
	ssize_t	rear;
}	t_stack;

typedef struct s_stacks
{
	t_stack	buffer;
	t_stack	stk_a;
	t_stack	stk_b;
	int		*array;
}	t_stacks;

int		stack_init(t_stack *tmp, int cap);
int		stack_append(t_stack *tmp, int c);
int		stack_delete(t_stack *temp);

/*circular queue */
void	add_rear(t_stack *stack, int data);
void	add_front(t_stack *stack, int data);
int		delete_rear(t_stack *stack);
int		delete_front(t_stack *stack);
int		is_empty(t_stack *stack);

/* show queue */
int		show_front(t_stack *stack);
int		show_rear(t_stack *stack);
int		show_nxt_front(t_stack *stack);
int		show_value(t_stack *stack, int loc, int idx);
int		get_stk_len(t_stack *stk);

/* get stack */
t_stack	*get_cur_stk(t_stacks *stks, int opt);
t_stack	*get_opposit_stk(t_stacks *stks, int opt);
#endif
