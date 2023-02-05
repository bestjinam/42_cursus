# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2023/02/02 12:10:24 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = 				philo	

# bonus target
BONUS_NAME =		philo

# cmd & options 
CC = 				cc
AR = 				ar
ARFLAGS = 			crs
RM = 				rm
RMFLAGS = 			-f

include ./config/variables.mk
include ./config/compile_rules.mk
# object file
M_OBJCS = $(addprefix $(OUT_DIR)/$(M_DIR)/, $(addsuffix .o, $(M_FILES)))
B_OBJCS = $(addprefix $(OUT_DIR)/$(B_DIR)/, $(addsuffix .o, $(B_FILES)))

ifdef	WITH_NOFLAGS
	CFLAGS =			-Werror	
else
	CFLAGS =			-Wall -Wextra -Werror
endif

ifdef	WITH_BONUS
	RM_OBJS = $(M_OBJCS)
	OBJECTS = $(B_OBJCS)
else
	RM_OBJS = $(B_OBJCS)
	OBJECTS = $(M_OBJCS)
endif

all : $(NAME)

bonus :
	make WITH_BONUS=1 all
no	:
	make WITH_NOFLAGS=1 all

$(NAME) : $(OBJECTS) 
	$(RM) $(RMFLAGS) $(RM_OBJS)
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
