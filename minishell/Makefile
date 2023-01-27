# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 13:48:24 by dham              #+#    #+#              #
#    Updated: 2023/01/25 18:55:49 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# target
NAME = minishell

# bonus target
BONUS_NAME = minishell

# cmd & options
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDE_OPTION = -I$(INCLUDE_DIR)
LIBFT_LINKING = -L$(LIBFT_DIR) -lft

RDLN_COMPILE = -I$(RDLN_DIR)/include
RDLN_LINKING = -L$(RDLN_DIR)/lib -lreadline

# Library 
# Libft
LIB_NAME = libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)

# gnl
GNL_DIR =		$(LIB_DIR)/get_next_line
GNL_FILES = 	get_next_line \
				get_next_line_utils 

# Dirs
INCLUDE_DIR = ./mandatory/includes/
LIBFT_DIR = ./libft/libft
RDLN_DIR = ${shell brew --prefix readline}

M_DIR = mandatory
B_DIR = minishell_bonus
ASCII = ascii
BUILTIN = builtin
EXECUTOR = executor
EXPANSION = expansion
PARSER = parser
SIGNAL = signal
UTILS = utils
OUT_DIR = objcs

# src files 

# ascii

ASCII_FILES =	ascii \
				ascii_1 \
				ascii_2 \
				ascii_3 \
				ascii_4 \
				ascii_5
# builtin
BUILTIN_FILES = builtin \
				builtin_utils \
				cd \
				cd_utils \
				echo \
				env \
				exit \
				export \
				pwd \
				unset
# executor
EXECUTOR_FILES = exe_ast \
				exe_cmd \
				exe_node \
				executor \
				redirection_fd_set \
				redirection_file_set 
# expansion
EXPANSION_FILES = 	escape \
				expand \
				heredoc_expand \
				wildcard \
				wildcard_readdir \
				wildcard_utils
# parser
PARSER_FILES = 	bracket \
		 		lexer \
		 		lexer_utils \
		 		make_bracket_tree \
		 		parser \
		 		parser_strctl \
		 		parser_utils
# signal
SIGNAL_FILES = 	ft_handler \
				ft_signal \
				terminal_ctl 
# utils
UTILS_FILES =	env_proc \
				env_proc2 \
				error_utils \
				heredoc \
				info_init \
				path_find \
				shell_split \
				strctl \
				utils

# file_set

M_FILES = main $(addprefix $(ASCII)/, $(ASCII_FILES)) \
		  $(addprefix $(BUILTIN)/, $(BUILTIN_FILES)) \
		  $(addprefix $(EXECUTOR)/, $(EXECUTOR_FILES)) \
		  $(addprefix $(EXPANSION)/, $(EXPANSION_FILES)) \
		  $(addprefix $(PARSER)/, $(PARSER_FILES)) \
		  $(addprefix $(SIGNAL)/, $(SIGNAL_FILES)) \
		  $(addprefix $(UTILS)/, $(UTILS_FILES))

B_FILES = main_bonus $(addprefix $(ASCII)/, $(addsuffix _bonus, $(ASCII_FILES))) \
		  $(addprefix $(BUILTIN)/, $(addsuffix _bonus, $(BUILTIN_FILES))) \
		  $(addprefix $(EXECUTOR)/, $(addsuffix _bonus, $(EXECUTOR_FILES))) \
		  $(addprefix $(EXPANSION)/, $(addsuffix _bonus, $(EXPANSION_FILES))) \
		  $(addprefix $(PARSER)/, $(addsuffix _bonus, $(PARSER_FILES))) \
		  $(addprefix $(SIGNAL)/, $(addsuffix _bonus, $(SIGNAL_FILES))) \
		  $(addprefix $(UTILS)/, $(addsuffix _bonus,  $(UTILS_FILES)))


G_FILES	= $(addprefix $(GNL_DIR)/, $(GNL_FILES))


# compile_rules

$(OUT_DIR)/$(M_DIR)/%.o : $(M_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(M_DIR)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(ASCII)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(BUILTIN)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(EXECUTOR)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(EXPANSION)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(PARSER)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(SIGNAL)
	@mkdir -p $(OUT_DIR)/$(M_DIR)/$(UTILS)
	$(CC) -c $(CFLAGS) $(RDLN_COMPILE) $(INCLUDE_OPTION) $< -o $@

$(OUT_DIR)/$(B_DIR)/%.o : $(B_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(B_DIR)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(ASCII)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(BUILTIN)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(EXECUTOR)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(EXPANSION)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(PARSER)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(SIGNAL)
	@mkdir -p $(OUT_DIR)/$(B_DIR)/$(UTILS)

	$(CC) -c $(CFLAGS) $(RDLN_COMPILE) $(INCLUDE_OPTION) $< -o $@

$(OUT_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(GNL_DIR)
	$(CC) -c $(CFLAGS) $(RDLN_COMPILE) $(INCLUDE_OPTION) $< -o $@

# object file
M_OBJCS = $(addprefix $(OUT_DIR)/$(M_DIR)/, $(addsuffix .o, $(M_FILES)))
B_OBJCS = $(addprefix $(OUT_DIR)/$(B_DIR)/, $(addsuffix .o, $(B_FILES)))
GNL_OBJCS = $(addprefix $(OUT_DIR)/, $(addsuffix .o, $(G_FILES)))

# BONUS OPTION

ifdef	WITH_BONUS
	RM_OBJS = $(M_OBJCS)
	OBJECTS = $(B_OBJCS) $(GNL_OBJCS)
else
	RM_OBJS = $(B_OBJCS)
	OBJECTS = $(M_OBJCS) $(GNL_OBJCS)
endif

all: $(NAME)

bonus :
	make WITH_BONUS=1 all

$(NAME): $(OBJECTS)
	$(MAKE) -C$(LIBFT_DIR) all
	$(RM) $(RM_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LINKING) $(RDLN_LINKING)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OUT_DIR)

fclean: clean
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean bonus fclean re
