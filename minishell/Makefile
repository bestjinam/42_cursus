# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/12/26 19:45:52 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = 				minishell

# bonus target
BONUS_NAME =		minishell

# cmd & options 
CC = 				cc
CFLAGS =			-Wall -Wextra -Werror #-fsanitize=address -g3
RLLFLAGS = 			-L/Users/jinam/.brew/opt/readline/lib -lreadline
RLCFLAGS = 			-I/Users/jinam/.brew/opt/readline/include
AR = 				ar
ARFLAGS = 			crs
RM = 				rm
RMFLAGS = 			-rf

include ./config/variables.mk
include ./config/compile_rules.mk
# object file
M_OBJCS = $(addprefix $(OUT_DIR)/$(M_DIR)/, $(addsuffix .o, $(M_FILES)))
B_OBJCS = $(addprefix $(OUT_DIR)/$(B_DIR)/, $(addsuffix .o, $(B_FILES)))
S_OBJCS = $(addprefix $(OUT_DIR)/$(S_DIR)/, $(addsuffix .o, $(S_FILES)))
ifdef	WITH_BONUS
	RM_OBJS = $(M_OBJCS)
	OBJECTS = $(B_OBJCS) $(S_OBJCS)
else
	RM_OBJS = $(B_OBJCS)
	OBJECTS = $(M_OBJCS) $(S_OBJCS)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME) : $(OBJECTS) 
	@make -C $(LIB_DIR) printf_gnl
	$(RM) $(RMFLAGS) $(RM_OBJS)
	$(CC) $(CFLAGS) $(RLLFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

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
