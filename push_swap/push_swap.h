/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:32:08 by jinam             #+#    #+#             */
/*   Updated: 2022/10/17 21:29:07 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* stack : int buffer array */
#include <unistd.h>

typedef struct	s_stack
{
	int	*buffer;
	ssize_t	len;
	ssize_t	cap;
	ssize_t	front;
	ssize_t	rear;
}	t_int_stack;

int	stack_init(t_int_stack *tmp, int cap);
int	stack_append(t_int_stack	*tmp, int c);
int	stack_delete(t_int_stack *temp);

/*operations*/
int	sa(t_int_stack *stack_a, t_int_stack *stack_b);
int	sb(t_int_stack *stack_a, t_int_stack *stack_b);
int	ss(t_int_stack *stack_a, t_int_stack *stack_b);
int	pa(t_int_stack *stack_a, t_int_stack *stack_b);
int	pb(t_int_stack *stack_a, t_int_stack *stack_b);
int	ra(t_int_stack *stack_a, t_int_stack *stack_b);
int	rb(t_int_stack *stack_a, t_int_stack *stack_b);
int	rr(t_int_stack *stack_a, t_int_stack *stack_b);
int	rra(t_int_stack *stack_a, t_int_stack *stack_b);
int	rrb(t_int_stack *stack_a, t_int_stack *stack_b);
int	rrr(t_int_stack *stack_a, t_int_stack *stack_b);

/* ft_series */

void	*ft_memcpy(void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi_base(const char *str, char *base);
char	**ft_split(char const *s, char c);

#endif
