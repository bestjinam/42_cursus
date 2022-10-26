/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:22:01 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 10:15:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "triangle_map.h"

static void	calculate_idx_and_size(int depth, int *m_idx, int *size)
{	
	int	i;
	*m_idx = 0;
	*size = 1;
	i = -1;
	while (++i < depth)
	{

		*m_idx = *m_idx * 3 + 1;
		*size *= 3;
	}
}

static void	two_elements_sorting_a(t_stacks *stacks, int opt)
{
	if (opt == 0)
	{
		if (show_front(&stacks->stack_a) < show_nxt_front(&stacks->stack_a))
			sa(stacks);
	}
	else
	{
		if (show_front(&stacks->stack_a) > show_nxt_front(&stacks->stack_a))
			sa(stacks);
	}
}

static void	three_elements_sorting_a(t_stacks *stks, int opt)
{
	int	i;

	i = -1;
	two_elements_sorting_a(stks, opt);
	while (opt == 0 && (++i < 2 && show_front(&stks->stack_a) > show_rear(&stks->stack_a)))
		pb(stks);
	while (opt == 1 && (++i < 2 && show_front(&stks->stack_a) < show_rear(&stks->stack_a)))
		pb(stks);
	rra(stks);
	pb(stks);
	while (++i <= 2)
		pb(stks);
}
static void	four_elements_sorting_a(t_stacks *stks, int opt)
{
	int	i;

	i = -1;
	three_elements_sorting_a(stks, opt);
	printf("bstack > %d, %d, %d\n", show_value(&stks->stack_b, 0, 0),show_value(&stks->stack_b, 0, 1),show_value(&stks->stack_b, 0, 2));
	rb(stks);
	rb(stks);
	rb(stks);
	printf("bstack rear > %d, %d, %d\n", show_value(&stks->stack_b, 1, 1),show_value(&stks->stack_b, 1, 2),show_value(&stks->stack_b, 1, 3));
	while (opt == 0 && (++i < 3 && show_front(&stks->stack_a) < show_rear(&stks->stack_b)))
		rrb(stks);
	while (opt == 1 && (++i < 3 && show_front(&stks->stack_a) > show_rear(&stks->stack_b)))
		rrb(stks);
	pb(stks);
	while (++i <= 3)
		rrb(stks);
}

static void	five_elements_sorting_a(t_stacks *stks, int opt)
{
	int	i;
	int	j; 

	three_elements_sorting_a(stks, opt);
	rb(stks);
	rb(stks);
	rb(stks);
	two_elements_sorting_a(stks, opt);
	i = 0;
	j = 0;
	while (i < 2 && j < 3)
	{
		if (opt == 0 && show_front(&stks->stack_a) < show_rear(&stks->stack_b))
		{
			rrb(stks);
			j ++;
		}
		else if (opt == 1 && show_front(&stks->stack_a) > show_rear(&stks->stack_b))
		{
			rrb(stks);
			j++;
		}
		else
		{
			pb(stks);
			i ++;
		}
	}
	while (i < 2)
	{
		pb(stks);
		i++;
	}
	while (j < 3)
	{
		rrb(stks);
		j++;
	}
}

void	push_tri_to_b(t_stacks *stacks, int size, int opt)
{
	int	i;

	if (size == 2)
	{
		two_elements_sorting_a(stacks, opt);
		pb(stacks);
		pb(stacks);
	}
	else if (size == 3)
		three_elements_sorting_a(stacks, opt);
	else if (size == 4)
		four_elements_sorting_a(stacks, opt);
	else if (size == 5)
		five_elements_sorting_a(stacks, opt);
}

void first_stack_a_move(t_stacks *stacks, t_triangle_map *map)
{
	int	i;
	int	m_idx;
	int	size;

	i = -1;
	calculate_idx_and_size(map->depth, &m_idx, &size);
	while (++i < size)
	{
		printf(">>map->values : %d\n shapes: %d\n", map->values[m_idx + i], map->shapes[m_idx + i]);
		if (map->shapes[m_idx + i] == UP)
			push_tri_to_b(stacks, map->values[m_idx + i], UP);
		else
			push_tri_to_b(stacks, map->values[m_idx + i], DOWN);
	}
	triangle_map_destroy(map);
}
