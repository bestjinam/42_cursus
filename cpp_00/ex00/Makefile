# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 17:26:49 by jinam             #+#    #+#              #
#    Updated: 2023/04/16 20:50:43 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target
NAME = megaphone

# Cmd & Options 
CC 			= c++
CXXFLAGS 	= -Wall -Wextra -Werror
RM			= rm
RMFLAGS		= -f
OUT_DIR 	= objs
FILE 		= megaphone
OBJECTS		= $(addprefix $(OUT_DIR)/, $(addsuffix .o, $(FILE)))

# Compile rules
$(OUT_DIR)/%.o	: %.cpp
	@mkdir -p $(OUT_DIR)
	$(CC) -c $(CXXFLAGS) $< -o $@

debug	:
	make WITH_NOFLAGS=1 all

ifdef	WITH_NOFLAGS
	CXXFLAGS =	-fsanitize=address -g3
endif

.PHONY : all no clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	@$(RM) $(RMFLAGS) -r $(OUT_DIR)

fclean	: clean
	@$(RM) $(RMFLAGS) $(NAME)

re		:
	@make fclean
	@make all
