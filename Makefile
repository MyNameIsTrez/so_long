# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/07/13 14:24:29 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := so_long

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
# CFLAGS += -O3 # -O1 adds tail recursion detection

################################################################################

GLFW_FRAMEWORKS :=\
	-framework Cocoa\
	-framework OpenGL\
	-framework IOKit

GLFW := -lglfw3 $(GLFW_FRAMEWORKS)

MLX42_PATH := ./submodules/MLX42
MLX42_LIB_PATH := $(MLX42_PATH)/libmlx42.a
MLX42 := -L$(MLX42_PATH) -lmlx42

LIBFT_PATH := ./submodules/libft
LIBFT_LIB_PATH := $(LIBFT_PATH)/libft.a
LIBFT := -L$(LIBFT_PATH) -lft

FT_PRINTF_PATH := ./submodules/ft_printf
FT_PRINTF_LIB_PATH := $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF := -L$(FT_PRINTF_PATH) -lftprintf

LIBS := $(GLFW) $(MLX42) $(LIBFT) $(FT_PRINTF)

################################################################################

SOURCES :=\
	src/background/background.c

################################################################################

SOURCES +=\
	src/cleanup/cleanup.c

################################################################################

SOURCES +=\
	src/error/sl_any_error.c\
	src/error/sl_get_error_ptr.c\
	src/error/sl_get_error.c\
	src/error/sl_print_all_errors.c\
	src/error/sl_print_error.c\
	src/error/sl_set_error.c

################################################################################

SOURCES +=\
	src/frames/utils/utils.c\
	src/frames/update_frames.c

################################################################################

SOURCES +=\
	src/held_keys/update_held_keys.c

################################################################################

SOURCES +=\
	src/iterators/frames/channel_indices.c\
	src/iterators/frames/frame_channels.c\
	src/iterators/frames/frame_height.c\
	src/iterators/frames/frame_pixels.c\
	src/iterators/frames/frame_width.c

SOURCES +=\
	src/iterators/char_grid_height.c\
	src/iterators/char_grid_width.c\
	src/iterators/char_grid.c\
	src/iterators/entities.c\
	src/iterators/frame_count.c\
	src/iterators/keys.c\
	src/iterators/player_count.c\
	src/iterators/tile_kind_count.c

################################################################################

SOURCES +=\
	src/players/utils/utils.c\
	src/players/players.c

################################################################################

SOURCES +=\
	src/tiles/tiles.c

################################################################################

SOURCES +=\
	src/utils/0_utils.c

################################################################################

SOURCES +=\
	src/0_main.c\
	src/1_parse_argv.c\
	src/2_load_texture.c\
	src/3_instantiate_tile_kinds.c\
	src/4_instantiate_tile_grid.c\
	src/5_instantiate_entities.c\
	src/6_instantiate_players.c

################################################################################

# HEADERS =\
# 	src/background/sl_background.h\
# 	src/cleanup/sl_cleanup.h\
# 	src/error/sl_error.h\
# 	src/frames/utils/sl_frame_utils.h\
# 	src/frames/sl_frames.h\
# 	src/held_keys/sl_held_keys.h\
# 	src/iterators/sl_iterators.h\
# 	src/iterators/frames/sl_iterator_frames.h\
# 	src/players/utils/sl_players_utils.h\
# 	src/players/sl_players.h\
# 	src/settings/sl_settings_controls.h\
# 	src/settings/sl_settings_map.h\
# 	src/settings/sl_settings_players.h\
# 	src/settings/sl_settings_texture.h\
# 	src/settings/sl_settings_tiles.h\
# 	src/settings/sl_settings_window.h\
# 	src/settings/sl_settings.h\
# 	src/structs/sl_structs_data.h\
# 	src/structs/sl_structs_entity.h\
# 	src/structs/sl_structs_mlx42.h\
# 	src/structs/sl_structs_player.h\
# 	src/structs/sl_structs_structs.h\
# 	src/structs/sl_structs_temporary.h\
# 	src/structs/sl_structs_texture.h\
# 	src/structs/sl_structs_tiles.h\
# 	src/tiles/sl_tiles.h\
# 	src/utils/sl_utils.h\
# 	src/so_long.h

################################################################################

BONUS_SOURCES :=

ifdef ADD_BONUS
SOURCES += $(BONUS_SOURCES)
endif

################################################################################

FCLEANED_FILES := $(NAME)

ifdef DEBUG
LIBS +=
HEADERS +=
CFLAGS += -g3 -Wconversion
FCLEANED_FILES +=
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

################################################################################

OBJECT_PATHS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

INCLUDES := $(sort $(addprefix -I, $(MLX42_PATH)/include $(LIBFT_PATH) $(FT_PRINTF_PATH)/src))

################################################################################

all: $(PRE_RULES) $(MLX42_LIB_PATH) $(LIBFT_LIB_PATH) $(FT_PRINTF_LIB_PATH) $(NAME)

################################################################################

$(MLX42_LIB_PATH):
	$(MAKE) -C $(MLX42_PATH)

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_LIB_PATH):
	$(MAKE) -C $(FT_PRINTF_PATH)

################################################################################

$(NAME): $(OBJECT_PATHS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECT_PATHS) -o $(NAME)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	rm -f $(FCLEANED_FILES)
	$(MAKE) -C $(MLX42_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

bonus:
	@$(MAKE) ADD_BONUS=1 all

################################################################################

.PHONY: all clean fclean re bonus

################################################################################
