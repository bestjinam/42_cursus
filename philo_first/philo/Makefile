# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2023/02/10 16:03:21 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = 				philo	

# bonus target
BONUS_NAME =		philo

# cmd & options 
CC = 				cc
RM = 				rm
RMFLAGS = 			-f

include ../config/variables.mk
include ../config/compile_rules.mk

# object file

OBJECTS = $(addprefix $(OUT_DIR)/, $(addsuffix .o, $(M_FILES)))

# option setting
ifdef	WITH_NOFLAGS
	CFLAGS =			-fsanitize=thread	-g3
else
	CFLAGS =			-Wall -Wextra -Werror
endif
all : $(NAME)


debug	:
	make WITH_NOFLAGS=1 all

$(NAME) : $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

.PHONY : all bonus no

.PHONY : clean
clean :
	@$(RM) $(RMFLAGS) -r $(OUT_DIR)

.PHONY : fclean
fclean : clean
	@$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

.PHONY : re
re :
	@make fclean
	@make all
