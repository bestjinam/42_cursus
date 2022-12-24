# library

# LIBFT
LIB_NAME = libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)

# file name

S_FILES =			ms_env_structure \
					ms_lexer_structure \
					ms_parser_structure \
					ms_structure_init_utils


M_FILES = 			ms_error_handling \
					ms_main \
					ms_prompt_function \
					ms_signal_functions

B_FILES = 			ms_error_handling \
					ms_main \
					ms_prompt_function \
					ms_signal_functions
# file directory

OUT_DIR = 			objcs
B_DIR =				bonus_minishell
M_DIR =				mandatory_minishell
S_DIR =				structure
