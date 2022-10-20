/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:32:08 by jinam             #+#    #+#             */
/*   Updated: 2022/10/20 14:44:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* stack : int buffer array */
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
	t_stack	stack_a;
	t_stack	stack_b;
	int		*array;
}	t_stacks;

int		stack_init(t_stack *tmp, int cap);
int		stack_append(t_stack *tmp, int c);
int		stack_delete(t_stack *temp);

/*operations*/
int		sa(t_stack *stack_a, t_stack *stack_b);
int		sb(t_stack *stack_a, t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack_a, t_stack *stack_b);
int		rb(t_stack *stack_a, t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		rra(t_stack *stack_a, t_stack *stack_b);
int		rrb(t_stack *stack_a, t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);

/* ft_series */
void	*ft_memcpy(void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol_base(const char *str, char *base);
char	**ft_split(char const *s, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
