# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/08/31 15:59:18 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := so_long

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror -Wconversion -Wpedantic -Wfatal-errors
CFLAGS += -Wno-gnu-binary-literal # so_long autotiling
CFLAGS += -Wno-overlength-strings # MLX42

################################################################################

ifeq ($(shell uname), Darwin)
GLFW_FRAMEWORKS :=\
	-framework Cocoa\
	-framework OpenGL\
	-framework IOKit
endif

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

# SOURCES += $(shell find ./src -type f -name "*.c")

SOURCES +=\
	./src/background/private/instantiate_background/fill_background.c\
	./src/background/instantiate_background.c\
	./src/char_grid/private/init_char_grid/has_basic_characters/missing_collectible.c\
	./src/char_grid/private/init_char_grid/has_basic_characters/missing_exit.c\
	./src/char_grid/private/init_char_grid/has_basic_characters/missing_start.c\
	./src/char_grid/private/init_char_grid/map_is_not_enclosed/cell_is_not_wall.c\
	./src/char_grid/private/init_char_grid/map_is_not_enclosed/row_is_not_enclosed.c\
	./src/char_grid/private/init_char_grid/check_duplicate_start_or_exit_character.c\
	./src/char_grid/private/init_char_grid/check_invalid_character.c\
	./src/char_grid/private/init_char_grid/has_basic_characters.c\
	./src/char_grid/private/init_char_grid/map_is_not_enclosed.c\
	./src/char_grid/get_char_grid_character.c\
	./src/char_grid/init_char_grid.c\
	./src/cleanup/private/cleanup/mlx_cleanup.c\
	./src/cleanup/cleanup.c\
	./src/collectibles/private/instantiate_collectibles/instantiate_collectible.c\
	./src/collectibles/collect_collectible.c\
	./src/collectibles/instantiate_collectibles.c\
	./src/entities/private/instantiate_entities/instantiate_entity.c\
	./src/entities/hide_and_disable_entity.c\
	./src/entities/instantiate_entities.c\
	./src/entities/is_entity.c\
	./src/entities/update_entities.c\
	./src/error/private/print_all_errors/sl_print_error.c\
	./src/error/private/sl_get_error.c\
	./src/error/private/sl_get_error_ptr.c\
	./src/error/sl_any_error.c\
	./src/error/sl_print_all_errors.c\
	./src/error/sl_set_error.c\
	./src/exit_locks/private/instantiate_exit_locks/instantiate_exit_lock.c\
	./src/exit_locks/private/update_exit_locks/update_exit_lock.c\
	./src/exit_locks/instantiate_exit_locks.c\
	./src/exit_locks/open_exit_locks.c\
	./src/exit_locks/update_exit_locks.c\
	./src/frames/private/initialize_tile_kinds_colors/initialize_visible_frames/initialize_channels.c\
	./src/frames/private/initialize_tile_kinds_colors/initialize_visibile_frames.c\
	./src/frames/private/update_frame_colors/step_channel/bounce_high.c\
	./src/frames/private/update_frame_colors/step_channel/bounce_low.c\
	./src/frames/private/update_frame_colors/step_channel/get_channel_ptr.c\
	./src/frames/private/update_frame_colors/step_channel/get_channel_step_ptr.c\
	./src/frames/private/update_frame_colors/step_channel/get_max_channel.c\
	./src/frames/private/update_frame_colors/step_channel/get_min_channel.c\
	./src/frames/private/update_frame_colors/step_channel/get_original_channel.c\
	./src/frames/private/update_frame_colors/should_step.c\
	./src/frames/private/update_frame_colors/step_channel.c\
	./src/frames/private/is_visible.c\
	./src/frames/change_frame.c\
	./src/frames/change_frames.c\
	./src/frames/get_frame.c\
	./src/frames/get_frame_instance.c\
	./src/frames/initialize_tile_kinds_colors.c\
	./src/frames/update_frame_colors.c\
	./src/held_keys/update_held_keys.c\
	./src/init/private/init/parse_argv/get_scale.c\
	./src/init/private/init/parse_argv.c\
	./src/init/private/init/subinits.c\
	./src/init/init.c\
	./src/iterators/frames/frame_count.c\
	./src/iterators/frames/frame_pixel_indices.c\
	./src/iterators/frames/frames.c\
	./src/iterators/frames/rgb_channel_indices.c\
	./src/iterators/char_grid_characters.c\
	./src/iterators/char_grid_indices.c\
	./src/iterators/collectibles.c\
	./src/iterators/entities.c\
	./src/iterators/exit_locks.c\
	./src/iterators/headings.c\
	./src/iterators/keys.c\
	./src/iterators/monsters.c\
	./src/iterators/player_movement_keys.c\
	./src/iterators/players.c\
	./src/iterators/tile_kinds.c\
	./src/level/private/reset_level/reset_collectibles.c\
	./src/level/private/reset_level/reset_exit_locks.c\
	./src/level/private/reset_level/reset_monsters.c\
	./src/level/private/reset_level/reset_players.c\
	./src/level/reset_level.c\
	./src/loop/loop.c\
	./src/monitor/init_monitor_size.c\
	./src/monsters/private/instantiate_monsters/instantiate_monster.c\
	./src/monsters/private/update_monsters/update_monster.c\
	./src/monsters/private/is_player_in_way.c\
	./src/monsters/private/kill_player.c\
	./src/monsters/instantiate_monsters.c\
	./src/monsters/set_monster_heading.c\
	./src/monsters/update_monsters.c\
	./src/players/private/initialize_players/get_player_controls.c\
	./src/players/private/update_players/update_player/update_alive_player/try_collect_collectible/entities_have_same_position.c\
	./src/players/private/update_players/update_player/update_alive_player/try_move/trying_to_move/can_autowalk.c\
	./src/players/private/update_players/update_player/update_alive_player/try_move/trying_to_move.c\
	./src/players/private/update_players/update_player/update_alive_player/try_move/update_death_state.c\
	./src/players/private/update_players/update_player/update_alive_player/try_collect_collectible.c\
	./src/players/private/update_players/update_player/update_alive_player/try_move.c\
	./src/players/private/update_players/update_player/update_alive_player/try_walk_into_exit.c\
	./src/players/private/update_players/update_player/dying.c\
	./src/players/private/update_players/update_player/update_alive_player.c\
	./src/players/private/update_players/update_player.c\
	./src/players/initialize_players.c\
	./src/players/start_player_dying.c\
	./src/players/update_players.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind/sanitize_max_color.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind/sanitize_min_color.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_collectible.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_empty_space.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_map_exit.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_1.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_2.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_wall.c\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds.c\
	./src/sanitize/private/sanitize/sanitize_argc.c\
	./src/sanitize/private/sanitize/sanitize_argv.c\
	./src/sanitize/private/sanitize/sanitize_defines.c\
	./src/sanitize/sanitize.c\
	./src/texture/private/init_texture_metadata/set_pixels_per_tile.c\
	./src/texture/private/init_texture_metadata/set_real_scale.c\
	./src/texture/private/load_texture/get_texture_filepath/get_texture_scales_path.c\
	./src/texture/private/load_texture/init_texture_filename/get_texture_filename_stem/get_str_pixels_per_tile.c\
	./src/texture/private/load_texture/init_texture_filename/get_texture_filename_stem.c\
	./src/texture/private/load_texture/get_texture_filepath.c\
	./src/texture/private/load_texture/init_texture_filename.c\
	./src/texture/init_texture_metadata.c\
	./src/texture/load_texture.c\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path/add_unvisited_neighbors/try_add_neighbor.c\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path/add_unvisited_neighbors.c\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path/floodfill.c\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path.c\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index/get_neighboring_walls/neighboring_wall.c\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index/bits_are_on.c\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index/get_neighboring_walls.c\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index.c\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile.c\
	./src/tile_grid/check_valid_players_path.c\
	./src/tile_grid/get_heading_column.c\
	./src/tile_grid/get_heading_index.c\
	./src/tile_grid/get_heading_row.c\
	./src/tile_grid/get_tile_grid_character.c\
	./src/tile_grid/instantiate_tile_grid.c\
	./src/tile_grid/sl_try_get_index.c\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/add_tile_kind_frames/add_tile_kind_frame.c\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/add_tile_kind_frames.c\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind.c\
	./src/tile_kinds/private/instantiate_tile_kinds/collectible.c\
	./src/tile_kinds/private/instantiate_tile_kinds/empty_space.c\
	./src/tile_kinds/private/instantiate_tile_kinds/exit_lock.c\
	./src/tile_kinds/private/instantiate_tile_kinds/map_exit.c\
	./src/tile_kinds/private/instantiate_tile_kinds/monster.c\
	./src/tile_kinds/private/instantiate_tile_kinds/player_1.c\
	./src/tile_kinds/private/instantiate_tile_kinds/player_2.c\
	./src/tile_kinds/private/instantiate_tile_kinds/wall_tile.c\
	./src/tile_kinds/get_entity_tile_kind.c\
	./src/tile_kinds/get_tile_grid_tile_kind.c\
	./src/tile_kinds/instantiate_tile_kinds.c\
	./src/tiles/private/can_walk/is_entity_in_way.c\
	./src/tiles/private/instantiate_tile_frames/instantiate_tile_frame.c\
	./src/tiles/can_walk.c\
	./src/tiles/fill_tile_data.c\
	./src/tiles/get_column.c\
	./src/tiles/get_index.c\
	./src/tiles/get_instance_x.c\
	./src/tiles/get_instance_y.c\
	./src/tiles/get_row.c\
	./src/tiles/get_tile_column.c\
	./src/tiles/get_tile_row.c\
	./src/tiles/instantiate_tile_frames.c\
	./src/tiles/is_tile_walkable.c\
	./src/tiles/out_of_bounds.c\
	./src/tiles/set_tile_pos.c\
	./src/tiles/shift_tile_pos_to_heading.c\
	./src/window/private/init_window_width_and_height/init_window_height.c\
	./src/window/private/init_window_width_and_height/init_window_width.c\
	./src/window/private/update_window/get_draw_string/get_allocation_count_string.c\
	./src/window/private/update_window/get_draw_string/get_fps_string.c\
	./src/window/private/update_window/get_draw_string/get_movement_count_string.c\
	./src/window/private/update_window/draw_allocation_count.c\
	./src/window/private/update_window/draw_fps.c\
	./src/window/private/update_window/draw_movement_count.c\
	./src/window/init_window_width_and_height.c\
	./src/window/update_window.c\
	./src/main.c

################################################################################

# HEADERS += $(shell find ./src -type f -name "*.h")

HEADERS +=\
	./src/background/private/instantiate_background/sl_private_instantiate_background.h\
	./src/background/sl_background.h\
	./src/char_grid/private/init_char_grid/has_basic_characters/sl_private_has_basic_characters.h\
	./src/char_grid/private/init_char_grid/map_is_not_enclosed/sl_private_map_is_not_enclosed.h\
	./src/char_grid/private/init_char_grid/sl_private_init_char_grid.h\
	./src/char_grid/sl_char_grid.h\
	./src/cleanup/private/cleanup/sl_private_cleanup.h\
	./src/cleanup/sl_cleanup.h\
	./src/collectibles/private/instantiate_collectibles/sl_private_instantiate_collectibles.h\
	./src/collectibles/sl_collectibles.h\
	./src/collectibles/sl_struct_collectible.h\
	./src/entities/private/instantiate_entities/sl_private_instantiate_entities.h\
	./src/entities/sl_entities.h\
	./src/entities/sl_struct_entity.h\
	./src/error/private/print_all_errors/sl_private_print_all_errors.h\
	./src/error/private/sl_private_error.h\
	./src/error/sl_error.h\
	./src/exit_locks/private/instantiate_exit_locks/sl_private_instantiate_exit_locks.h\
	./src/exit_locks/private/update_exit_locks/sl_private_update_exit_locks.h\
	./src/exit_locks/sl_exit_locks.h\
	./src/exit_locks/sl_struct_exit_lock.h\
	./src/frames/private/initialize_tile_kinds_colors/initialize_visible_frames/sl_private_initialize_visible_frames.h\
	./src/frames/private/initialize_tile_kinds_colors/sl_private_initialize_tile_kinds_colors.h\
	./src/frames/private/update_frame_colors/step_channel/sl_private_step_channel.h\
	./src/frames/private/update_frame_colors/sl_private_update_frame_colors.h\
	./src/frames/private/sl_private_frames.h\
	./src/frames/sl_frames.h\
	./src/held_keys/sl_held_keys.h\
	./src/init/private/init/parse_argv/sl_private_parse_argv.h\
	./src/init/private/init/sl_private_init.h\
	./src/init/sl_init.h\
	./src/iterators/frames/sl_iterator_frames.h\
	./src/iterators/sl_iterators.h\
	./src/iterators/sl_struct_iterators.h\
	./src/level/private/reset_level/sl_private_reset_level.h\
	./src/level/sl_level.h\
	./src/loop/sl_loop.h\
	./src/monitor/sl_monitor.h\
	./src/monitor/sl_struct_monitor.h\
	./src/monsters/private/instantiate_monsters/sl_private_instantiate_monsters.h\
	./src/monsters/private/update_monsters/sl_private_update_monsters.h\
	./src/monsters/private/sl_private_monsters.h\
	./src/monsters/sl_monsters.h\
	./src/monsters/sl_struct_monster.h\
	./src/players/private/initialize_players/sl_private_initialize_players.h\
	./src/players/private/update_players/update_player/update_alive_player/try_collect_collectible/sl_private_try_collect_collectible.h\
	./src/players/private/update_players/update_player/update_alive_player/try_move/trying_to_move/sl_private_trying_to_move.h\
	./src/players/private/update_players/update_player/update_alive_player/try_move/sl_private_try_move.h\
	./src/players/private/update_players/update_player/update_alive_player/sl_private_update_alive_player.h\
	./src/players/private/update_players/update_player/sl_private_update_player.h\
	./src/players/private/update_players/sl_private_update_players.h\
	./src/players/sl_players.h\
	./src/players/sl_struct_player.h\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind/sl_private_sanitize_tile_kind.h\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sl_private_sanitize_thing_tile_kind.h\
	./src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sl_private_sanitize_tile_kinds.h\
	./src/sanitize/private/sanitize/sanitize_defines/sl_private_sanitize_defines.h\
	./src/sanitize/private/sanitize/sl_private_sanitize.h\
	./src/sanitize/sl_sanitize.h\
	./src/settings/tile_kinds/sl_settings_tile_kinds.h\
	./src/settings/tile_kinds/sl_tile_kind_collectible.h\
	./src/settings/tile_kinds/sl_tile_kind_empty_space.h\
	./src/settings/tile_kinds/sl_tile_kind_exit_lock.h\
	./src/settings/tile_kinds/sl_tile_kind_map_exit.h\
	./src/settings/tile_kinds/sl_tile_kind_monster.h\
	./src/settings/tile_kinds/sl_tile_kind_wall.h\
	./src/settings/tile_kinds/sl_tile_kinds_players.h\
	./src/settings/sl_settings.h\
	./src/settings/sl_settings_background.h\
	./src/settings/sl_settings_controls.h\
	./src/settings/sl_settings_map_characters.h\
	./src/settings/sl_settings_monitor.h\
	./src/settings/sl_settings_players.h\
	./src/settings/sl_settings_texture.h\
	./src/settings/sl_settings_window.h\
	./src/structs/sl_structs.h\
	./src/structs/sl_structs_data.h\
	./src/structs/sl_structs_mlx42.h\
	./src/texture/private/init_texture_metadata/sl_private_init_texture_metadata.h\
	./src/texture/private/load_texture/get_texture_filepath/sl_private_get_texture_filepath.h\
	./src/texture/private/load_texture/init_texture_filename/get_texture_filename_stem/sl_private_get_texture_filename_stem.h\
	./src/texture/private/load_texture/init_texture_filename/sl_private_init_texture_filename.h\
	./src/texture/private/load_texture/sl_private_load_texture.h\
	./src/texture/sl_struct_texture.h\
	./src/texture/sl_texture.h\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path/add_unvisited_neighbors/sl_private_add_unvisited_neighbors.h\
	./src/tile_grid/private/check_valid_players_path/check_valid_player_path/sl_private_check_valid_player_path.h\
	./src/tile_grid/private/check_valid_players_path/sl_private_check_valid_players_path.h\
	./src/tile_grid/private/check_valid_players_path/sl_private_path_struct.h\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index/get_neighboring_walls/sl_private_get_neighboring_walls.h\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_wall_frame_index/sl_private_get_wall_frame_index.h\
	./src/tile_grid/private/instantiate_tile_grid/instantiate_tile/sl_private_instantiate_tile.h\
	./src/tile_grid/private/instantiate_tile_grid/sl_private_instantiate_tile_grid.h\
	./src/tile_grid/sl_struct_tile_grid.h\
	./src/tile_grid/sl_tile_grid.h\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/add_tile_kind_frames/sl_private_add_tile_kind_frames.h\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/sl_private_add_tile_kind.h\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h\
	./src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/sl_private_add_thing_tile_kind.h\
	./src/tile_kinds/private/instantiate_tile_kinds/sl_private_instantiate_tile_kinds.h\
	./src/tile_kinds/sl_struct_tile_kind.h\
	./src/tile_kinds/sl_tile_kinds.h\
	./src/tiles/private/can_walk/sl_private_tile_can_walk.h\
	./src/tiles/private/instantiate_tile_frames/sl_private_instantiate_tile_frames.h\
	./src/tiles/sl_struct_tiles.h\
	./src/tiles/sl_tiles.h\
	./src/window/private/init_window_width_and_height/sl_private_init_window_width_and_height.h\
	./src/window/private/update_window/get_draw_string/sl_private_get_draw_string.h\
	./src/window/private/update_window/sl_private_update_window.h\
	./src/window/sl_struct_window.h\
	./src/window/sl_window.h\
	./src/so_long.h

################################################################################

FCLEANED_FILES := $(NAME)

ifdef O3
CFLAGS += -O3
endif

ifdef DEBUG
CFLAGS += -g3
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

ifdef BONUS
CFLAGS += -DBONUS=1
else
CFLAGS += -DBONUS=0
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

.PHONY: all
all: $(PRE_RULES) $(NAME)

################################################################################

$(NAME): $(MLX42_LIB_PATH) $(LIBFT_LIB_PATH) $(FT_PRINTF_LIB_PATH) $(OBJECT_PATHS)
	$(CC) $(CFLAGS) $(OBJECT_PATHS) $(LIBS) -o $(NAME)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

################################################################################

$(MLX42_LIB_PATH):
	git submodule update --init --recursive
	$(MAKE) -C $(MLX42_PATH)

$(LIBFT_LIB_PATH):
	git submodule update --init --recursive
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_LIB_PATH):
	git submodule update --init --recursive
	$(MAKE) -C $(FT_PRINTF_PATH)

################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/

.PHONY: fclean
fclean: clean
	git submodule update --init --recursive
	rm -f $(FCLEANED_FILES)
	$(MAKE) -C $(MLX42_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

.PHONY: re
re: fclean all

.PHONY: bonus
bonus:
	@$(MAKE) BONUS=1 all

################################################################################
