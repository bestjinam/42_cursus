/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:15:33 by jinam             #+#    #+#             */
/*   Updated: 2022/11/03 17:34:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORTING_H
# define PUSH_SWAP_SORTING_H

# include "../triangle_map/triangle_map.h"
# include "../data_structure/data_structure.h"
# include "../ps_commands/op.h"

typedef struct s_min_max
{
	int	min;
	int	max;
	int	mid;
}	t_min_max;

enum e_direction
{
	TO_B = 0,
	TO_A = 1
};

void	merge_sort(int left, int right, t_stacks *stacks);
void	get_max_min(int *arr, int size, t_min_max *min_max);

int		init_sorting(t_stacks *stacks);
void	small_sorting_process(t_stacks *stks);
void	big_sorting_process(t_stacks *stks);
void	dividing_processing(t_stacks *stacks, t_triangle_map *map);
void	conquering_processing(t_stacks *stks, t_triangle_map *map);

long	get_max_int(long n1, long n2, long n3);
long	get_min_int(long n1, long n2, long n3);
void	get_max_min(int *arr, int size, t_min_max *min_max);
/* making triangles */

void	two_elements_sorting_a(t_stacks *stacks, int opt);
void	three_elements_sorting_a(t_stacks *stks, int opt);
void	four_elements_sorting_a(t_stacks *stks, int opt);
void	five_elements_sorting_a(t_stacks *stks, int opt);

int		making_up(t_stacks *stks, int *val, int opt);
int		making_down(t_stacks *stks, int *val, int opt);

#endif
