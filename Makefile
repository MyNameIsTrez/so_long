# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/07/29 15:22:25 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := so_long

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror

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

SOURCES +=\
	src/cleanup/cleanup.c\
	src/cleanup/mlx_cleanup.c

SOURCES +=\
	src/entities/entities.c

SOURCES +=\
	src/error/sl_any_error.c\
	src/error/sl_get_error_ptr.c\
	src/error/sl_get_error.c\
	src/error/sl_print_all_errors.c\
	src/error/sl_print_error.c\
	src/error/sl_set_error.c

SOURCES +=\
	src/frames/utils/utils.c\
	src/frames/change_frames.c\
	src/frames/initialize_tile_kinds_colors.c\
	src/frames/update_frame_colors.c

SOURCES +=\
	src/grid/grid.c\
	src/grid/init_grid.c

SOURCES +=\
	src/held_keys/update_held_keys.c

SOURCES +=\
	src/init/init.c\
	src/init/parse_argv.c\
	src/init/subinits.c

SOURCES +=\
	src/iterators/frames/rgb_channel_indices.c\
	src/iterators/frames/frame_rgb_channel_indices.c\
	src/iterators/frames/frame_count.c\
	src/iterators/frames/frame_height.c\
	src/iterators/frames/frame_pixel_indices.c\
	src/iterators/frames/frame_pixels.c\
	src/iterators/frames/frame_width.c\
	src/iterators/frames/frames_pixel_indices.c\
	src/iterators/frames/frames.c

SOURCES +=\
	src/iterators/char_grid_height.c\
	src/iterators/char_grid_width.c\
	src/iterators/char_grid.c\
	src/iterators/entities.c\
	src/iterators/keys.c\
	src/iterators/players.c\
	src/iterators/player_movement_keys.c\
	src/iterators/tile_kinds.c

SOURCES +=\
	src/loop/loop.c

SOURCES +=\
	src/monitor/init_monitor_size.c

SOURCES +=\
	src/players/utils/utils.c\
	src/players/players.c

SOURCES +=\
	src/texture/init_texture_filename/init_texture_filename.c\
	src/texture/load_texture/load_texture.c\
	src/texture/set_real_scale/set_real_scale.c\
	src/texture/init_texture.c

SOURCES +=\
	src/tile_kinds/utils/utils.c\
	src/tile_kinds/instantiate_tile_kinds.c

SOURCES +=\
	src/tiles/tiles.c

SOURCES +=\
	src/utils/0_utils.c

SOURCES +=\
	src/window/window.c

SOURCES +=\
	src/main.c\
	src/3_instantiate_tile_grid.c\
	src/4_instantiate_entities.c\
	src/5_initialize_players.c

################################################################################

HEADERS +=\
	src/background/sl_background.h

HEADERS +=\
	src/cleanup/sl_cleanup.h

HEADERS +=\
	src/entities/sl_entities.h

HEADERS +=\
	src/error/sl_error.h

HEADERS +=\
	src/frames/utils/sl_frame_utils.h\
	src/frames/sl_frames.h

HEADERS +=\
	src/grid/sl_grid.h

HEADERS +=\
	src/held_keys/sl_held_keys.h

HEADERS +=\
	src/init/sl_init.h

HEADERS +=\
	src/iterators/sl_iterators.h\
	src/iterators/frames/sl_iterator_frames.h

HEADERS +=\
	src/loop/sl_loop.h

HEADERS +=\
	src/monitor/sl_monitor.h

HEADERS +=\
	src/players/utils/sl_players_utils.h\
	src/players/sl_players.h

HEADERS +=\
	src/settings/tile_kinds/sl_settings_tile_kinds.h\
	src/settings/tile_kinds/sl_collectible.h\
	src/settings/tile_kinds/sl_empty_space.h\
	src/settings/tile_kinds/sl_map_exit.h\
	src/settings/tile_kinds/sl_player.h\
	src/settings/tile_kinds/sl_wall.h

HEADERS +=\
	src/settings/sl_settings_background.h\
	src/settings/sl_settings_controls.h\
	src/settings/sl_settings_map.h\
	src/settings/sl_settings_monitor.h\
	src/settings/sl_settings_players.h\
	src/settings/sl_settings_texture.h\
	src/settings/sl_settings_window.h\
	src/settings/sl_settings.h

HEADERS +=\
	src/structs/sl_structs_data.h\
	src/structs/sl_structs_entity.h\
	src/structs/sl_structs_iterators.h\
	src/structs/sl_structs_mlx42.h\
	src/structs/sl_structs_monitor.h\
	src/structs/sl_structs_player.h\
	src/structs/sl_structs.h\
	src/structs/sl_structs_texture.h\
	src/structs/sl_structs_tiles.h

HEADERS +=\
	src/texture/init_texture_filename/sl_init_texture_filename.h\
	src/texture/load_texture/sl_load_texture.h\
	src/texture/set_real_scale/sl_set_real_scale.h\
	src/texture/sl_texture.h

HEADERS +=\
	src/tile_kinds/utils/sl_tile_kinds_utils.h\
	src/tile_kinds/sl_tile_kinds.h

HEADERS +=\
	src/tiles/sl_tiles.h

HEADERS +=\
	src/utils/sl_utils.h

HEADERS +=\
	src/window/sl_window.h

HEADERS +=\
	src/so_long.h

################################################################################

BONUS_SOURCES :=

ifdef ADD_BONUS
SOURCES += $(BONUS_SOURCES)
endif

################################################################################

FCLEANED_FILES := $(NAME)

ifdef O3
CFLAGS += -O3
endif

ifdef DEBUG
CFLAGS += -g3
CFLAGS += -Wconversion
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
