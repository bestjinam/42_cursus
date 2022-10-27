/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:32:08 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 15:42:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* stack : int buffer array */

# include <unistd.h>
# include <stdio.h>
# include "triangle_map.h"

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
	t_stack	commands;
	int		*array;
}	t_stacks;

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

typedef struct s_min_max
{
	int	min;
	int	max;
	int	mid;
}	t_min_max;

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

/*pre sort*/
void	merge_sort(int left, int right, t_stacks *stacks);
void	get_max_min(int *arr, int size, t_min_max *min_max);

/*sorting process*/
void	small_sorting_process(t_stacks *stks, t_min_max *min_max);
void	big_sorting_process(t_stacks *stks);

/*dividing process*/

void	two_elements_sorting_a(t_stacks *stacks, int opt);
void	three_elements_sorting_a(t_stacks *stks, int opt);
void	four_elements_sorting_a(t_stacks *stks, int opt);
void	five_elements_sorting_a(t_stacks *stks, int opt);

/*operations*/
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

/* ft_series */
void	*ft_memcpy(void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol_base(const char *str, char *base);
char	**ft_split(char const *s, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putnbr(int n);
int		ft_putstr(char *temp_str);

/*sorting process*/
int		init_sorting(t_stacks *stacks);
void	show_stack_status(t_stack *stack);
void	dividing_processing(t_stacks *stacks, t_triangle_map *map);
void	conquering_processing(t_stacks *stks, t_triangle_map *map);

#endif
