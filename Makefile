# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/08/05 16:22:53 by sbos          ########   odam.nl          #
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
	src/background/private/instantiate_background/fill_background.c\
	src/background/instantiate_background.c

SOURCES +=\
	src/char_grid/private/init_char_grid/char_grid_has_invalid_character.c\
	src/char_grid/get_char_grid_character.c\
	src/char_grid/init_char_grid.c

SOURCES +=\
	src/cleanup/private/cleanup/mlx_cleanup.c\
	src/cleanup/cleanup.c

SOURCES +=\
	src/entities/private/instantiate_entities/instantiate_entity.c\
	src/entities/instantiate_entities.c\
	src/entities/is_entity.c\
	src/entities/update_entities.c

SOURCES +=\
	src/error/private/sl_get_error_ptr.c\
	src/error/private/sl_get_error.c\
	src/error/private/sl_print_error.c\
	src/error/sl_any_error.c\
	src/error/sl_print_all_errors.c\
	src/error/sl_set_error.c

SOURCES +=\
	src/frames/private/update_frame_colors/should_step.c\
	src/frames/private/update_frame_colors/step_pixel.c\
	src/frames/private/is_opaque.c\
	src/frames/change_frames.c\
	src/frames/get_frame.c\
	src/frames/get_frame_instance.c\
	src/frames/get_pixel_index.c\
	src/frames/initialize_tile_kinds_colors.c\
	src/frames/update_frame_colors.c

SOURCES +=\
	src/held_keys/update_held_keys.c

SOURCES +=\
	src/init/private/init/parse_argv/get_scale.c\
	src/init/private/init/parse_argv.c\
	src/init/private/init/subinits.c\
	src/init/init.c

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
	src/iterators/monsters.c\
	src/iterators/player_movement_keys.c\
	src/iterators/players.c\
	src/iterators/tile_kinds.c

SOURCES +=\
	src/loop/loop.c

SOURCES +=\
	src/monitor/init_monitor_size.c

SOURCES +=\
	src/monsters/private/update_monsters/update_monster.c\
	src/monsters/instantiate_monsters.c\
	src/monsters/update_monsters.c

SOURCES +=\
	src/players/private/initialize_players/get_player_controls.c\
	src/players/private/try_move_players/can_player_shift/is_walkable/get_key_column_offset.c\
	src/players/private/try_move_players/can_player_shift/is_walkable/get_key_row_offset.c\
	src/players/private/try_move_players/can_player_shift/is_walkable/is_entity_walkable.c\
	src/players/private/try_move_players/can_player_shift/is_walkable/is_tile_walkable.c\
	src/players/private/try_move_players/can_player_shift/can_autowalk.c\
	src/players/private/try_move_players/can_player_shift/is_walkable.c\
	src/players/private/try_move_players/can_player_shift.c\
	src/players/private/try_move_players/shift_player.c\
	src/players/initialize_players.c\
	src/players/try_move_players.c

SOURCES +=\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_color_offset/sanitize_max_color_offset.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_color_offset/sanitize_min_color_offset.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_collectible.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_empty_space.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_map_exit.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_1.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_2.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_wall.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kind.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds.c\
	src/sanitize/private/sanitize/sanitize_argc.c\
	src/sanitize/private/sanitize/sanitize_argv.c\
	src/sanitize/private/sanitize/sanitize_defines.c\
	src/sanitize/sanitize.c

SOURCES +=\
	src/texture/init_texture_filename_utils/get_str_pixels_per_tile.c\
	src/texture/init_texture_filename_utils/get_texture_filename_stem.c\
	src/texture/init_texture_metadata_utils/set_pixels_per_tile.c\
	src/texture/load_texture_utils/get_texture_filepath.c\
	src/texture/load_texture_utils/get_texture_scales_path.c\
	src/texture/init_texture_filename.c\
	src/texture/init_texture_metadata.c\
	src/texture/load_texture.c\
	src/texture/set_real_scale.c

SOURCES +=\
	src/tile_grid/instantiate_tile_grid_utils/get_tile_grid_tile_kind.c\
	src/tile_grid/instantiate_tile_grid_utils/instantiate_tile.c\
	src/tile_grid/instantiate_tile_grid_utils/malloc_tile_grid_cells.c\
	src/tile_grid/get_tile_grid_character.c\
	src/tile_grid/instantiate_tile_grid.c

SOURCES +=\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/collectible.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/empty_space.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/map_exit.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/monster.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/player_1.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/player_2.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/wall_tile.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind_frames.c\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind.c\
	src/tile_kinds/instantiate_tile_kinds_utils/instantiate_tile_kind_color.c\
	src/tile_kinds/get_character_tile_kind.c\
	src/tile_kinds/get_tile_kind.c\
	src/tile_kinds/instantiate_tile_kinds.c

SOURCES +=\
	src/tiles/fill_tile_data.c\
	src/tiles/instantiate_tile_frames.c\
	src/tiles/out_of_bounds.c\
	src/tiles/shift_tile_pos.c

SOURCES +=\
	src/window/init_window_width_and_height_utils/init_window_height.c\
	src/window/init_window_width_and_height_utils/init_window_width.c\
	src/window/init_window_width_and_height.c

SOURCES +=\
	src/main.c

################################################################################

HEADERS +=\
	src/background/private/instantiate_background/sl_private_instantiate_background.h\
	src/background/sl_background.h

HEADERS +=\
	src/char_grid/private/init_char_grid/sl_private_init_char_grid.h\
	src/char_grid/sl_char_grid.h

HEADERS +=\
	src/cleanup/private/cleanup/sl_private_cleanup.h\
	src/cleanup/sl_cleanup.h

HEADERS +=\
	src/entities/private/instantiate_entities/sl_private_instantiate_entities.h\
	src/entities/sl_entities.h\
	src/entities/sl_struct_entity.h

HEADERS +=\
	src/error/private/sl_private_error.h\
	src/error/sl_error.h

HEADERS +=\
	src/frames/private/update_frame_colors/sl_private_update_frame_colors.h\
	src/frames/private/sl_private_frames.h\
	src/frames/sl_frames.h

HEADERS +=\
	src/held_keys/sl_held_keys.h

HEADERS +=\
	src/init/private/init/parse_argv/sl_private_parse_argv.h\
	src/init/private/init/sl_private_init.h\
	src/init/sl_init.h

HEADERS +=\
	src/iterators/sl_iterators.h\
	src/iterators/frames/sl_iterator_frames.h\
	src/iterators/sl_struct_iterators.h

HEADERS +=\
	src/loop/sl_loop.h

HEADERS +=\
	src/monitor/sl_monitor.h\
	src/monitor/sl_struct_monitor.h

HEADERS +=\
	src/monsters/private/update_monsters/sl_private_update_monsters.h\
	src/monsters/sl_monsters.h\
	src/monsters/sl_struct_monster.h

HEADERS +=\
	src/players/private/initialize_players/sl_private_initialize_players.h\
	src/players/private/try_move_players/can_player_shift/is_walkable/sl_private_is_walkable.h\
	src/players/private/try_move_players/can_player_shift/sl_private_can_player_shift.h\
	src/players/private/try_move_players/sl_private_try_move_players.h\
	src/players/sl_players.h\
	src/players/sl_struct_player.h

HEADERS +=\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_color_offset/sl_private_sanitize_color_offset.h\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sl_private_sanitize_tile_kinds.h\
	src/sanitize/private/sanitize/sanitize_defines/sl_private_sanitize_defines.h\
	src/sanitize/private/sanitize/sl_private_sanitize.h\
	src/sanitize/sl_sanitize.h

HEADERS +=\
	src/settings/tile_kinds/players/sl_player_1.h\
	src/settings/tile_kinds/players/sl_player_2.h\
	src/settings/tile_kinds/sl_collectible.h\
	src/settings/tile_kinds/sl_empty_space.h\
	src/settings/tile_kinds/sl_map_exit.h\
	src/settings/tile_kinds/sl_monster.h\
	src/settings/tile_kinds/sl_settings_tile_kinds.h\
	src/settings/tile_kinds/sl_wall.h

HEADERS +=\
	src/settings/sl_settings_background.h\
	src/settings/sl_settings_controls.h\
	src/settings/sl_settings_map_characters.h\
	src/settings/sl_settings_monitor.h\
	src/settings/sl_settings_players.h\
	src/settings/sl_settings_texture.h\
	src/settings/sl_settings_window.h\
	src/settings/sl_settings.h

HEADERS +=\
	src/structs/sl_structs_data.h\
	src/structs/sl_structs_mlx42.h\
	src/structs/sl_structs.h

HEADERS +=\
	src/texture/init_texture_filename_utils/sl_init_texture_filename_utils.h\
	src/texture/init_texture_metadata_utils/sl_init_texture_metadata_utils.h\
	src/texture/load_texture_utils/sl_load_texture_utils.h\
	src/texture/sl_struct_texture.h\
	src/texture/sl_texture.h

HEADERS +=\
	src/tile_grid/instantiate_tile_grid_utils/sl_instantiate_tile_grid_utils.h\
	src/tile_grid/sl_struct_tile_grid.h\
	src/tile_grid/sl_tile_grid.h

HEADERS +=\
	src/tile_kinds/instantiate_tile_kinds_utils/add_tile_kind/sl_instantiate_tile_kinds_utils_add_tile_kind.h\
	src/tile_kinds/instantiate_tile_kinds_utils/sl_instantiate_tile_kinds_utils.h\
	src/tile_kinds/sl_struct_tile_kind.h\
	src/tile_kinds/sl_tile_kinds.h

HEADERS +=\
	src/tiles/sl_struct_tiles.h\
	src/tiles/sl_tiles.h

HEADERS +=\
	src/window/init_window_width_and_height_utils/sl_init_window_width_and_height_utils.h\
	src/window/sl_window.h

HEADERS +=\
	src/so_long.h

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

ifdef BONUS
CFLAGS += -DBONUS=
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

INCLUDES := $(sort $(addprefix -I, $(MLX42_PATH)/include $(LIBFT_PATH) $(FT_PRINTF_PATH)/src src))

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
	@$(MAKE) BONUS=1 all

################################################################################

.PHONY: all clean fclean re bonus

################################################################################
