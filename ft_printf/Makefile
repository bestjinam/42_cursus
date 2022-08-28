# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:24:05 by jinam             #+#    #+#              #
#    Updated: 2022/08/25 21:56:25 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
LBFT_DIR = ./libft
LBFT = $(LBFT_DIR)/libft.a
CC = cc -Wall -Wextra -Wall
$(NAME): all

all: mandatory_all
bonus: bonus_all
clean:
	rm -f ft_printf.o _printf_c.o _printf_d.o _printf_p.o _printf_s.o _printf_u.o \
	_printf_x.o ft_printf_bonus.o _printf_c_bonus.o _printf_d_bonus.o \
	_printf_p_bonus.o _printf_s_bonus.o _printf_u_bonus.o _printf_x_bonus.o \
	ft_printf_nbr_utils_bonus.o ft_printf_common_utils_bonus.o \
	ft_printf_common_utils.o ft_printf_nbr_utils.o
	@make -C$(LBFT_DIR) clean
fclean: 
	$(MAKE) clean
	@make -C$(LBFT_DIR) fclean
	rm -f $(NAME)
re: 
	$(MAKE) fclean
	$(MAKE) all

mandatory_all :  ft_printf.o _printf_c.o _printf_d.o _printf_p.o _printf_s.o \
	_printf_u.o _printf_x.o ft_printf_common_utils.o ft_printf_nbr_utils.o 
	rm -f $(NAME) ft_printf_bonus.o _printf_c_bonus.o _printf_d_bonus.o \
	_printf_p_bonus.o _printf_s_bonus.o _printf_u_bonus.o _printf_x_bonus.o
	@make -C$(LBFT_DIR) all
	cp $(LBFT) $(NAME)
	$(AR) cr $(NAME) $^

bonus_all :  ft_printf_bonus.o _printf_c_bonus.o _printf_d_bonus.o \
	_printf_p_bonus.o _printf_s_bonus.o _printf_u_bonus.o _printf_x_bonus.o \
	ft_printf_common_utils_bonus.o ft_printf_nbr_utils_bonus.o
	rm -f $(NAME) ft_printf.o _printf_c.o _printf_d.o _printf_p.o _printf_s.o \
	_printf_u.o _printf_x.o
	@make -C$(LBFT_DIR) all
	cp $(LBFT) $(NAME)
	$(AR) cr $(NAME) $^

.PHONY: all bonus clean fclean re mandatory_all bonus_all

_printf_c_bonus.o: _printf_c_bonus.c ft_printf_bonus.h libft/libft.h
_printf_d_bonus.o: _printf_d_bonus.c ft_printf_bonus.h libft/libft.h
_printf_p_bonus.o: _printf_p_bonus.c ft_printf_bonus.h libft/libft.h
_printf_s_bonus.o: _printf_s_bonus.c ft_printf_bonus.h libft/libft.h
_printf_u_bonus.o: _printf_u_bonus.c ft_printf_bonus.h libft/libft.h
_printf_x_bonus.o: _printf_x_bonus.c ft_printf_bonus.h libft/libft.h
ft_printf_bonus.o: ft_printf_bonus.c libft/libft.h ft_printf_bonus.h
ft_printf_common_utils_bonus.o: ft_printf_common_utils_bonus.c \
  ft_printf_bonus.h libft/libft.h
ft_printf_nbr_utils_bonus.o: ft_printf_nbr_utils_bonus.c \
  ft_printf_bonus.h libft/libft.h

_printf_c.o: _printf_c.c ft_printf.h libft/libft.h
_printf_d.o: _printf_d.c ft_printf.h libft/libft.h
_printf_p.o: _printf_p.c ft_printf.h libft/libft.h
_printf_s.o: _printf_s.c ft_printf.h libft/libft.h
_printf_u.o: _printf_u.c ft_printf.h libft/libft.h
_printf_x.o: _printf_x.c ft_printf.h libft/libft.h
ft_printf.o: ft_printf.c libft/libft.h ft_printf.h
ft_printf_common_utils.o: ft_printf_common_utils.c ft_printf.h \
  libft/libft.h
ft_printf_nbr_utils.o: ft_printf_nbr_utils.c ft_printf.h libft/libft.h
