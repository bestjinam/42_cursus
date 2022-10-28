# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/10/28 07:46:17 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= push_swap 
SRCS		=	ds_circular_queue.c          init_sorting_process.c       sort_big_dividing.c \
			  	ds_stack.c                   op_push.c                    sort_big_dividing_elements.c \
				ft_atol_base.c               op_rev_rotate.c              triangle_map.c \
				ft_libft.c                   op_rotate.c                  triangle_map_show.c \
				ft_memcmp.c                  op_swap.c                    util_data_structure.c \
				ft_print_functions.c         small_sorting_process.c      util_merge_sort.c \
				ft_push_swap_main.c          sort_big_conquering.c \
				ft_split.c                   sort_big_conquering_utils.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
bonus : all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
