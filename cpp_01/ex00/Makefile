# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 16:30:29 by jinam             #+#    #+#              #
#    Updated: 2023/04/16 22:03:16 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target
NAME = Zombie

# Cmd & Options
CC			= c++
CXXFLAGS	= -Wall -Werror -Wextra
RM 			= rm
RMFLAGS		= -f
OUT_DIR		= objs
FILE		= main Zombie newZombie randomChump
OBJECTS		= $(addprefix $(OUT_DIR)/, $(addsuffix .o, $(FILE)))

# Compile rules
$(OUT_DIR)/%.o	: %.cpp
	@mkdir -p $(OUT_DIR)
	$(CC) -c $(CXXFLAGS) $< -o $@

debug	:
	make WITH_NOFLAG=1 all

ifdef	WITH_NOFLAG
	CXXFLAGS = -fsanitize=address -g3
endif

.PHONY	: all no clean fclean re

all		: $(NAME)

$(NAME)	: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	@$(RM) $(RMFLAGS) -r $(OUT_DIR)

fclean	: clean
	@$(RM) $(RMFLAGS) $(NAME)

re		:
	@make fclean
	@make all
