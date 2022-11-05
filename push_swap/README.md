# 전체 파일 구조 

.
├── Makefile
├── config
│   ├── compile_rules.mk
│   └── variables.mk
├── data_structure
│   ├── data_structure.h
│   ├── ds_circular_queue.c
│   ├── ds_get_utils.c
│   ├── ds_show_utils.c
│   └── ds_stack.c
├── libft
│   ├── Makefile
│   ├── ft_printf
│   │   ├── _printf_c.c
│   │   ├── _printf_d.c
│   │   ├── _printf_p.c
│   │   ├── _printf_s.c
│   │   ├── _printf_u.c
│   │   ├── _printf_x.c
│   │   ├── ft_printf.c
│   │   ├── ft_printf.h
│   │   ├── ft_printf_common_utils.c
│   │   └── ft_printf_nbr_utils.c
│   ├── get_next_line
│   │   ├── get_next_line_bonus.c
│   │   ├── get_next_line_bonus.h
│   │   └── get_next_line_utils_bonus.c
│   └── libft
│       ├── ft___lst_bonus.c
│       ├── ft___lst_del_bonus.c
│       ├── ft___lst_function_bonus.c
│       ├── ft__print_functions.c
│       ├── ft__stdlib.c
│       ├── ft__string.c
│       ├── ft__string_function.c
│       ├── ft__string_split.c
│       ├── ft_atol_base.c
│       ├── ft_ctype_case_mapping.c
│       ├── ft_ctype_classification.c
│       ├── ft_stdlib.c
│       ├── ft_string_atoi_base.c
│       ├── ft_string_comparison.c
│       ├── ft_string_concat.c
│       ├── ft_string_copying.c
│       ├── ft_string_duplicate.c
│       ├── ft_string_itoa_base.c
│       ├── ft_string_miscellaneous.c
│       ├── ft_string_search.c
│       ├── ft_string_temp.c
│       ├── ft_string_temp_function.c
│       └── libft.h
├── ps_bonus
│   ├── checker_bonus.c
│   ├── checker_bonus.h
│   ├── ds_bonus.h
│   ├── ds_circular_queue_bonus.c
│   ├── ds_get_utils_bonus.c
│   ├── ds_show_utils_bonus.c
│   ├── ds_stack_bonus.c
│   ├── ft_push_swap_error_handling_bonus.c
│   ├── init_stacks_bonus.c
│   ├── op_bonus.h
│   ├── op_push_bonus.c
│   ├── op_rev_rotate_bonus.c
│   ├── op_rotate_bonus.c
│   ├── op_swap_bonus.c
│   └── util_pre_sorting_bonus.c
├── ps_commands
│   ├── op.h
│   ├── op_push.c
│   ├── op_rev_rotate.c
│   ├── op_rotate.c
│   └── op_swap.c
├── ps_main
│   ├── ft_push_swap_error_handling.c
│   ├── ft_push_swap_main.c
│   ├── is_sorting.c
│   └── push_swap_main.h
├── ps_sorting
│   ├── bs_conquering_process.c
│   ├── bs_conquering_utils.c
│   ├── bs_dividing_elements.c
│   ├── bs_dividing_process.c
│   ├── bs_making_up_down.c
│   ├── init_sorting_process.c
│   ├── push_swap_sorting.h
│   ├── small_sorting_process.c
│   └── util_pre_sorting.c
└── triangle_map
    ├── triangle_map.c
    ├── triangle_map.h
    └── triangle_map_show.c


배열 순환 큐를 사용하기

## 자료 구조

- stack
    
    ```c
    typedef struct s_stack
    {
    	int		*buffer; //인트 배열 포인터
    	ssize_t	len; //들어간 요소 개수
    	ssize_t	cap; //배열의 사이즈
    	ssize_t	front; //가장 앞 인덱스 
    	ssize_t	rear; //가장 뒤 인덱스
    }	t_stack;
    ```
    
- stacks
    
    ```c
    typedef struct s_stacks
    {
    	t_stack	buffer; //입력 인자를 넣은 배열
    	t_stack	stack_a; 
    	t_stack	stack_b;
    	int		*array; //중복 확인 또는 피벗 설정을 위해 미리 정렬된 배열
    }	t_stacks;
    ```
    

## 자료구조 ADT

- stack_init
    
    ```c
    int	stack_init(t_stack *tmp, int cap)
    {
    	tmp->buffer = malloc(sizeof(int) * (cap + 1));
    	if (!tmp->buffer)
    		return (-1);
    	tmp->len = 0;
    	tmp->cap = cap + 1;
    	tmp->front = 0;
    	tmp->rear = 0;
    	return (1);
    }
    ```
    
- stack_append
    
    ```c
    int	stack_append(t_stack *tmp, int c)
    {
    	size_t	i;
    	int		*cpy_list;
    
    	i = -1;
    	if (tmp->len == tmp->cap)
    	{
    		tmp->cap *= 2;
    		cpy_list = malloc(sizeof(int) * tmp->cap);
    		if (!cpy_list)
    			return (-1);
    		ft_memcpy(cpy_list, tmp->buffer, tmp->len);
    		free(tmp->buffer);
    		tmp->buffer = cpy_list;
    	}
    	tmp->buffer[(tmp->len)++] = c;
    	return (1);
    }
    ```
    
- stack_delete
    
    ```c
    int	stack_delete(t_stack *temp)
    {
    	if (!temp)
    		return (-1);
    	free(temp->buffer);
    	temp->buffer = (void *) 0;
    	return (1);
    }
    ```
    
- add_rear
    
    ```c
    void	add_rear(t_stack *stack, int data)
    {
    	stack->buffer[stack->rear] = data;
    	stack->rear = (stack->rear + 1) % stack->cap;
    }
    ```
    
- add_front
    
    ```c
    void	add_front(t_stack *stack, int data)
    {
    	if (stack->front == 0)
    		stack->front = stack->cap - 1;
    	else
    		stack->front = stack->front - 1;
    	stack->buffer[stack->front] = data;
    }
    ```
    
- delete_rear
    
    ```c
    int	delete_rear(t_stack *stack)
    {
    	if (!is_empty(stack))
    	{
    		if (stack->rear == 0)
    			stack->rear = stack->cap - 1;
    		else
    			stack->rear --;
    		return (stack->buffer[stack->rear]);
    	}
    	return (-1);
    }
    ```
    
- delete_front
    
    ```c
    int	delete_front(t_stack *stack)
    {
    	int	tmp;
    
    	if (!is_empty(stack))
    	{
    		tmp = stack->buffer[stack->front];
    		stack->front = (stack->front + 1) % stack->cap;
    		return (tmp);
    	}
    	return (-1);
    }
    ```
    
- is_empty
    
    ```c
    int	is_empty(t_stack *stack)
    {
    	return (stack->front == stack->rear);
    }
    ```
# map을 읽어보자.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8e2d2f80-1a8f-43a2-87aa-d7f6c7667192/Untitled.png)

우리는 위와 같이 a stack에 정렬된 모습의 삼각형을 만들기 위해 큰 삼각형을  2개에서 5개 까지의 요소로 구성된 최소 단위의 삼각형이 될때까지 1 / 3씩 자르는 과정을 거쳐 쪼개고, 이 삼각형들을 다시 병합하여 정렬 하기로 하였다. 

앞서 계산한 맵을 사용해서 최소 단위 삼각형들로 구성된 삼각형들의 모양을 stack b에 담아 보자. 

map에는 각 단계별 (depth)별 삼각형들의 갯수와 모양이 담겨져 있다. 

 map의 depth를 이용해서 가장 마지막 depth에 존재하는 shape과 value값을 읽어 들일 수 있다. 이 정보를 사용해보자.

- depth 를 이용해서 삼진트리에서의 첫 idx와 size를 구하자
    
    ```c
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
    ```
    
- value값과 shape을 읽어보자
    
    ```c
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
    ```
    
    # 2.  최소 단위 삼각형 정렬하기
    
    최소 단위 삼각형들은 2, 3, 4, 5개의 요소를 담고 있다. 
    
    각 요소의 갯수별로 방법을 나눠서 b stack에 정렬해보기로 했다. 
    
    다른 sorting 함수들은 모두 b로 보내지지만, 2개 sorting 함수의 경우, 다른 함수들에서 편하게 사용하기 위해서 a stack에 그대로 남아있도록 하였다. 
    
    - sorting 함수 호출 함수
        
        ```c
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
        ```
        
    - 2개 sorting
        
        ```c
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
        ```
        
    - 3개 sorting
        
        ```c
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
        ```
        
    - 4개 sorting
        
        ```c
        static void	four_elements_sorting_a(t_stacks *stks, int opt)
        {
        	int	i;
        
        	i = -1;
        	three_elements_sorting_a(stks, opt);
        	rb(stks);
        	rb(stks);
        	rb(stks);
        	while (opt == 0 && (++i < 3 && show_front(&stks->stack_a) < show_rear(&stks->stack_b)))
        		rrb(stks);
        	while (opt == 1 && (++i < 3 && show_front(&stks->stack_a) > show_rear(&stks->stack_b)))
        		rrb(stks);
        	pb(stks);
        	while (++i <= 3)
        		rrb(stks);
        }
        ```
        
    - 5개 sorting
        
        ```c
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
        ```
      
      
     # 하드 코딩 왜…?

우리가 만드는 merge sort algorithm은 최소 6개 이상의 요소가 있을 때 활용한다. 

따라서 2개에서 5개 까지의 요소들은 따로 정렬을 해주어야 한다. 

- 3개 sorting
    
    ```c
    static void	_three_sorting(t_stacks *stacks, t_min_max *min_max)
    {
    	const int	front = stacks->stack_a.front;
    	const int	rear = (stacks->stack_b.rear + stacks->stack_b.cap - 1) \
    					% stacks->stack_b.cap;
    	const int	f_val = stacks->stack_a.buffer[front];
    	const int	r_val = stacks->stack_a.buffer[rear - 1];
    
    	if (f_val == min_max->min && r_val == min_max->max)
    		return ;
    	else if (f_val == min_max->min \
    			&& r_val == min_max->mid)
    	{
    		rra(stacks);
    		sa(stacks);
    	}
    	else if (f_val == min_max->mid && r_val == min_max->max)
    		sa(stacks);
    	else if (f_val == min_max->mid && r_val == min_max->min)
    		rra(stacks);
    	else if (f_val == min_max->max && r_val == min_max->mid)
    		ra(stacks);
    	else if (f_val == min_max->max && r_val == min_max->min)
    	{
    		sa(stacks);
    		rra(stacks);
    	}
    }
    ```
    
- 4개 sorting
    
    ```c
    static void	_four_sorting(t_stacks *stacks, t_min_max *min_max)
    {
    	int	n_mid_idx;
    	int	n_min_idx;
    
    	while (stacks->stack_a.buffer[stacks->stack_a.front] != min_max->min)
    		ra(stacks);
    	pb(stacks);
    	n_mid_idx = stacks->buffer.len / 2 + stacks->buffer.len / 4 - 1;
    	n_min_idx = stacks->buffer.len / 2 - 1;
    	min_max->min = stacks->array[n_min_idx];
    	min_max->mid = stacks->array[n_mid_idx];
    	_three_sorting(stacks, min_max);
    	pa(stacks);
    }
    ```
    
- 5개 sorting
    
    ```c
    static void	_five_sorting(t_stacks *stacks, t_min_max *min_max)
    {
    	int			i;
    	int			b_rear;
    
    	i = -1;
    	while (++i < 5)
    	{
    		if (stacks->stack_a.buffer[stacks->stack_a.front] <= stacks->array[1])
    			pb(stacks);
    		else
    			ra(stacks);
    	}
    	b_rear = (stacks->stack_b.rear + stacks->stack_b.cap - 1) \
    			% stacks->stack_b.cap;
    	if (stacks->stack_b.buffer[stacks->stack_b.front] < \
    			stacks->stack_b.buffer[b_rear])
    		sb(stacks);
    	min_max->min = stacks->array[2];
    	min_max->mid = stacks->array[3];
    	_three_sorting(stacks, min_max);
    	pa(stacks);
    	pa(stacks);
    }
    ```
