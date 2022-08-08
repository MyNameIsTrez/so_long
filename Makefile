# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/08/08 15:51:21 by sbos          ########   odam.nl          #
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
	src/error/private/print_all_errors/sl_print_error.c\
	src/error/private/sl_get_error_ptr.c\
	src/error/private/sl_get_error.c\
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
	src/iterators/heading.c\
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
	src/monsters/private/instantiate_monsters/instantiate_monster.c\
	src/monsters/private/set_monster_heading/get_heading_column_offset.c\
	src/monsters/private/set_monster_heading/get_heading_row_offset.c\
	src/monsters/private/update_monsters/update_monster.c\
	src/monsters/instantiate_monsters.c\
	src/monsters/set_monster_heading.c\
	src/monsters/update_monsters.c

SOURCES +=\
	src/players/private/initialize_players/get_player_controls.c\
	src/players/private/try_move_players/can_player_shift/can_autowalk.c\
	src/players/private/try_move_players/can_player_shift/is_walkable.c\
	src/players/private/try_move_players/can_player_shift.c\
	src/players/private/try_move_players/shift_player.c\
	src/players/initialize_players.c\
	src/players/try_move_players.c

SOURCES +=\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind/sanitize_max_color_offset.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind/sanitize_min_color_offset.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_thing_tile_kind/sanitize_tile_kind.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_collectible.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_empty_space.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_map_exit.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_1.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_player_2.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds/sanitize_wall.c\
	src/sanitize/private/sanitize/sanitize_defines/sanitize_tile_kinds.c\
	src/sanitize/private/sanitize/sanitize_argc.c\
	src/sanitize/private/sanitize/sanitize_argv.c\
	src/sanitize/private/sanitize/sanitize_defines.c\
	src/sanitize/sanitize.c

SOURCES +=\
	src/texture/private/init_texture_metadata/set_pixels_per_tile.c\
	src/texture/private/init_texture_metadata/set_real_scale.c\
	src/texture/private/load_texture/get_texture_filepath/get_texture_scales_path.c\
	src/texture/private/load_texture/init_texture_filename/get_texture_filename_stem/get_str_pixels_per_tile.c\
	src/texture/private/load_texture/init_texture_filename/get_texture_filename_stem.c\
	src/texture/private/load_texture/get_texture_filepath.c\
	src/texture/private/load_texture/init_texture_filename.c\
	src/texture/init_texture_metadata.c\
	src/texture/load_texture.c

SOURCES +=\
	src/tile_grid/private/instantiate_tile_grid/instantiate_tile/get_tile_grid_tile_kind.c\
	src/tile_grid/private/instantiate_tile_grid/instantiate_tile.c\
	src/tile_grid/private/instantiate_tile_grid/malloc_tile_grid_cells.c\
	src/tile_grid/get_heading_column.c\
	src/tile_grid/get_heading_row.c\
	src/tile_grid/get_tile_grid_character.c\
	src/tile_grid/instantiate_tile_grid.c

SOURCES +=\
	src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/add_tile_kind_frames.c\
	src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind/instantiate_tile_kind_color.c\
	src/tile_kinds/private/instantiate_tile_kinds/add_thing_tile_kind/add_tile_kind.c\
	src/tile_kinds/private/instantiate_tile_kinds/collectible.c\
	src/tile_kinds/private/instantiate_tile_kinds/empty_space.c\
	src/tile_kinds/private/instantiate_tile_kinds/map_exit.c\
	src/tile_kinds/private/instantiate_tile_kinds/monster.c\
	src/tile_kinds/private/instantiate_tile_kinds/player_1.c\
	src/tile_kinds/private/instantiate_tile_kinds/player_2.c\
	src/tile_kinds/private/instantiate_tile_kinds/wall_tile.c\
	src/tile_kinds/get_character_tile_kind.c\
	src/tile_kinds/get_tile_kind.c\
	src/tile_kinds/instantiate_tile_kinds.c

SOURCES +=\
	src/tiles/can_walk.c\
	src/tiles/fill_tile_data.c\
	src/tiles/instantiate_tile_frames.c\
	src/tiles/is_entity_in_way.c\
	src/tiles/is_tile_walkable.c\
	src/tiles/out_of_bounds.c\
	src/tiles/set_tile_pos.c\
	src/tiles/shift_tile_pos.c

SOURCES +=\
	src/window/private/init_window_width_and_height/init_window_height.c\
	src/window/private/init_window_width_and_height/init_window_width.c\
	src/window/init_window_width_and_height.c

SOURCES +=\
	src/main.c

################################################################################

# TODO: Replace with hardcoded headers before handing in
HEADERS += $(shell find ./src -type f -name "*.h")

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
