# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 13:20:42 by jinam             #+#    #+#              #
#    Updated: 2022/10/28 18:59:15 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_NAME= pushswap_ds.a
LIB_DIR = ds
LIB = $(LIB_DIR)/$(LIB_NAME)
# file name
PS_FILES = push_swap_main \
			push_swap_process_inputs \
			push_swap_sort_exceptional_cases \
			push_swap_reduce_commands

CMD_FILES = cmd_multiple_cmds \
			cmd_push \
			cmd_reverse_rotate \
			cmd_rotate \
			cmd_swap \

MG_FILES = merge_sort_compare \
			merge_sort_conquer \
			merge_sort_divide_and_push \
			merge_sort_get_idx_highest_priority \
			merge_sort

# file directory
PS_DIR = ps
CMD_DIR = push_swap_commands
MG_DIR = push_swap_merge_sort
OUT_DIR = objcs
# object file
PS_OBJCS = $(addprefix $(OUT_DIR)/, $(addsuffix .o ,$(PS_FILES)))
CMD_OBJCS = $(addprefix $(OUT_DIR)/$(CMD_DIR)/, $(addsuffix .o ,$(CMD_FILES)))
MG_OBJCS = $(addprefix $(OUT_DIR)/$(MG_DIR)/, $(addsuffix .o ,$(MG_FILES)))
OBJCS = $(PS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS)

$(NAME) : build
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(OBJCS) $(LIB) -o $@

.PHONY : build
build :
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(CMD_DIR)
	@mkdir -p $(OUT_DIR)/$(MG_DIR)
	@make compile

.PHONY : compile
compile : $(OBJCS)

$(OUT_DIR)/%.o : $(PS_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OUT_DIR)/$(CMD_DIR)/%.o : $(PS_DIR)/$(CMD_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OUT_DIR)/$(MG_DIR)/%.o : $(PS_DIR)/$(MG_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	make -C $(LIB_DIR) fclean
	@$(RM) $(RMFLAGS) $(OBJCS)
	@$(RM) $(RMFLAGS) $(OUT_DIR)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re :
	make fclean
	make all
