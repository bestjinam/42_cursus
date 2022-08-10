# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/08/10 20:06:57 by ggul_jam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a
SRCS		=  _printf_c.c \
			   _printf_s.c \
			  ft_printf.c ft_printf_common_utils.c
LBFT_DIR	= "./libft/"

OBJS		= $(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C$(LBFT_DIR) all
	cp	$(LBFT_DIR)/libft.a $(NAME)
	@ar -rc $@ $^

bonus : all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@make -C$(LBFT_DIR) clean

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LBFT_DIR)/libft.a

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
