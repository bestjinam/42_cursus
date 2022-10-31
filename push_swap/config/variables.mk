# library
LIB_NAME = libft.a
LIB_DIR = ft_utils
LIB = $(LIB_DIR)/$(LIB_NAME)

# file name

DS_FILES = 			ds_stack \
					ds_circular_queue \
					ds_get_utils \
					ds_show_utils

PS_MAIN_FILES =		ft_push_swap_main \
					ft_push_swap_error_handling

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

# file directory

DS_DIR =			data_structure
PS_MAIN_DIR = 		ps_main
PS_CMD_DIR = 		ps_commands
PS_SORTING_DIR =	ps_sorting
TRG_DIR =			triangle_map
OUT_DIR = 			objcs
