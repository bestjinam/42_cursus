# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/10/31 20:28:37 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = 				push_swap

# cmd & options 
CC = 				cc
CFLAGS =			-Wall -Wextra -Werror -fsanitize=address -g3
AR = 				ar
ARFLAGS = 			crs
RM = 				rm
RMFLAGS = 			-rf

include ./config/variables.mk

# object file
DS_OBJCS = $(addprefix $(OUT_DIR)/$(DS_DIR)/, $(addsuffix .o, $(DS_FILES)))
PS_MAIN_OBJCS = $(addprefix $(OUT_DIR)/$(PS_MAIN_DIR)/, $(addsuffix .o, $(PS_MAIN_FILES)))
PS_CMD_OBJCS = $(addprefix $(OUT_DIR)/$(PS_CMD_DIR)/, $(addsuffix .o, $(PS_CMD_FILES)))
PS_SORTING_OBJCS = $(addprefix $(OUT_DIR)/$(PS_SORTING_DIR)/, $(addsuffix .o, $(PS_SORTING_FILES)))
TRG_OBJCS = $(addprefix $(OUT_DIR)/$(TRG_DIR)/, $(addsuffix .o, $(TRG_FILES)))
OBJCS = $(DS_OBJCS) $(PS_MAIN_OBJCS) $(PS_CMD_OBJCS) $(PS_SORTING_OBJCS) $(TRG_OBJCS)

$(NAME) : $(OBJCS)
	make -C $(LIB_DIR) printf_gnl
	$(CC) $(CFLAGS) $(OBJCS) $(LIB) -o $(NAME)

include ./config/compile_rules.mk

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(OUT_DIR)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re :
	make fclean
	make all
