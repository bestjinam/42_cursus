# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/11/16 01:51:55 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = 				pipex	

# bonus target
BONUS_NAME =		pipex

# cmd & options 
CC = 				cc
CFLAGS =			-Wall -Wextra -Werror
AR = 				ar
ARFLAGS = 			crs
RM = 				rm
RMFLAGS = 			-rf

include ./config/variables.mk
include ./config/compile_rules.mk
# object file
M_OBJCS = $(addprefix $(OUT_DIR)/$(M_DIR)/, $(addsuffix .o, $(M_FILES)))
B_OBJCS = $(addprefix $(OUT_DIR)/$(B_DIR)/, $(addsuffix .o, $(B_FILES)))

ifdef	WITH_BONUS
	OBJECTS = $(B_OBJCS)
else
	OBJECTS = $(M_OBJCS)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME) : $(OBJECTS) 
	@make -C $(LIB_DIR) printf_gnl
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

.PHONY : all bonus

.PHONY : clean
clean :
	@make -C $(LIB_DIR) fclean
	@$(RM) $(RMFLAGS) $(OUT_DIR)

.PHONY : fclean
fclean : clean
	@$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

.PHONY : re
re :
	@make fclean
	@make all
