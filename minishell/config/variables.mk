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

M_FILES = 			minishell_env_parser \
					minishell_parser \
					ms_error_handling \
					ms_prompt_functions \
					minishell_lexer \
					minishell_parser_utils \
					minishell_redirector \
					ms_main \
					ms_heredoc_functions \
					ms_signal_functions \
					minishell_executer \
					ms_execve_functions \
					ms_exe_builtin_functions \
					minishell_executer_utils
					

B_FILES = 			ms_error_handling \
					ms_main \
					ms_prompt_functions \
					ms_signal_functions

BUILT_FILES = 		built_error \
					built_unset \
					built_env_util \
					built_echo \
					built_env \
					built_pwd \
					built_exit \
					built_export\
					built_cd
# file directory

OUT_DIR = 			objcs
B_DIR =				minishell_bonus
M_DIR =				minishell_mandatory
S_DIR =				structure
BUILT_DIR =			builtin
