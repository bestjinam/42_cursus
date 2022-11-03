# library
LIB_NAME = libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)

# file name

DS_FILES = 			ds_stack \
					ds_circular_queue \
					ds_get_utils \
					ds_show_utils

PS_MAIN_FILES =		ft_push_swap_main \
					ft_push_swap_error_handling \
					is_sorting

PS_CMD_FILES=		op_push \
					op_rev_rotate \
					op_rotate \
					op_swap	

PS_SORTING_FILES =	init_sorting_process \
					small_sorting_process \
					bs_dividing_process \
					bs_dividing_elements \
					bs_conquering_process \
					bs_conquering_utils \
					bs_making_up_down \
					util_pre_sorting

TRG_FILES =			triangle_map \
					triangle_map_show

BONUS_FILES = 		checker_bonus \
					op_push_bonus \
					op_rev_rotate_bonus \
					op_rotate_bonus \
					op_swap_bonus \
					ds_circular_queue_bonus \
					ds_get_utils_bonus \
					ds_show_utils_bonus \
					init_stacks_bonus \
					ft_push_swap_error_handling_bonus \
					util_pre_sorting_bonus \
					ds_stack_bonus
# file directory

DS_DIR =			data_structure
PS_MAIN_DIR = 		ps_main
PS_CMD_DIR = 		ps_commands
PS_SORTING_DIR =	ps_sorting
TRG_DIR =			triangle_map
OUT_DIR = 			objcs
BONUS_DIR =			ps_bonus
