/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:32:08 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 16:42:06 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* stack : int buffer array */

# include <unistd.h>
# include <stdio.h>

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
	t_stack	stack_a;
	t_stack	stack_b;
	int		*array;
}	t_stacks;

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

/*pre sort*/
void	merge_sort(int left, int right, t_stacks *stacks);
void	get_max_min(int *arr, int size, t_min_max *min_max);

/*operations*/
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_a);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

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
int	init_sorting(t_stacks *stacks);

#endif
