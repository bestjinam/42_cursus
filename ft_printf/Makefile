# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/08/03 12:04:49 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a
SRCS		= _convert_base.c \
			  _printf_d.c \
			  _printf_s.c \
			  ft_printf.c \
			  _printf_c.c \
			  _printf_p.c \
			  _printf_i.c \
			  _printf_u.c \
			  _printf_x.c \
			  _printf_xx.c \
			  _printf_per.c
LBFT_DIR	= "libft"

OBJS		= $(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LBFT_DIR) all
	cp	$(LBFT_DIR)/libft.a $(NAME)
	@ar -rc $@ $^

bonus : all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LBFT_DIR)

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
