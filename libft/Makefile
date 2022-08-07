# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/08/02 16:52:11 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	libft.a
SRCS		=	ft_ctype_classification.c ft_ctype_case_mapping.c \
				ft_string_copying.c \
				ft_string_concat.c \
				ft_string_duplicate.c \
				ft_string_miscellaneous.c \
				ft_string_search.c \
				ft_string_comparison.c \
				ft_stdlib.c \
				ft__print_functions.c\
				ft__string.c \
				ft__string_split.c \
				ft__stdlib.c \
				ft__string_function.c ft_string_atoi_base.c ft_string_itoa_base.c\

OBJS		=	$(SRCS:.c=.o)

BONUS_SRC	=	ft___lst_bonus.c\
				ft___lst_del_bonus.c\
				ft___lst_function_bonus.c
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

ifdef	WITH_BONUS
	OBJECTS = $(OBJS) $(BONUS_OBJ)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar -rc $@ $^

bonus :
	@make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
