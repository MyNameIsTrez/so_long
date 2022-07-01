/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 17:43:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SO_LONG_H
# define SO_LONG_H

////////////////////////////////////////////////////////////////////////////////

# include "MLX42/MLX42.h"

////////////////////////////////////////////////////////////////////////////////

# include "libft.h"
# include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

# include "a_utils.h"
# include "iterators/iterators.h"

////////////////////////////////////////////////////////////////////////////////

# define WINDOW_TITLE "so_long"
# define MAX_PLAYER_COUNT 2

# define PIXELS_PER_TILE_UNSCALED 8
# define DEFAULT_SCALE 3

////////////////////////////////////////////////////////////////////////////////

# define TEXTUREPACK "BitsyDungeonTiles/"
# define TEXTUREPACKS_PATH "texturepacks/"
# define TEXTURES_DIR "textures/"
# define TEXTURE_SCALES_DIR "texture_scales/"
# define TEXTURE_FILENAME_PREFIX "scale_"
# define TEXTURE_FILENAME_EXTENSION ".png"

////////////////////////////////////////////////////////////////////////////////

# define EMPTY_SPACE_TEXTURE_FRAME_COUNT 1
# define EMPTY_SPACE_TEXTURE_ROW 0
# define EMPTY_SPACE_CHARACTER '0'

# define WALL_TEXTURE_FRAME_COUNT 1
# define WALL_TEXTURE_ROW 3
# define WALL_CHARACTER '1'

# define COLLECTIBLE_TEXTURE_FRAME_COUNT 1
# define COLLECTIBLE_TEXTURE_ROW 43
# define COLLECTIBLE_CHARACTER 'C'

# define MAP_EXIT_TEXTURE_FRAME_COUNT 1
# define MAP_EXIT_TEXTURE_ROW 18
# define MAP_EXIT_CHARACTER 'E'

# define PLAYER_TEXTURE_FRAME_COUNT 1
# define PLAYER_TEXTURE_ROW 25
# define PLAYER_CHARACTER 'P'

////////////////////////////////////////////////////////////////////////////////

// TODO: Make sure that *only* the bonus has the enemy character and such here.
# define MAP_CHARACTERS	"01CEP"

# define ENTITY_CHARACTERS	"CP"

////////////////////////////////////////////////////////////////////////////////

# define PLAYER_1_UP_KEY MLX_KEY_W
# define PLAYER_1_DOWN_KEY MLX_KEY_S
# define PLAYER_1_LEFT_KEY MLX_KEY_A
# define PLAYER_1_RIGHT_KEY MLX_KEY_D

# define PLAYER_2_UP_KEY MLX_KEY_UP
# define PLAYER_2_DOWN_KEY MLX_KEY_DOWN
# define PLAYER_2_LEFT_KEY MLX_KEY_LEFT
# define PLAYER_2_RIGHT_KEY MLX_KEY_RIGHT

////////////////////////////////////////////////////////////////////////////////

typedef struct s_texture
{
	char			*filename;
	mlx_texture_t	*data;
}	t_texture;

typedef struct s_tile_type
{
	unsigned char	character;
	uint32_t		frame_count;
	mlx_image_t		**frames;
}	t_tile_type;

typedef struct s_tile
{
	t_tile_type	*tile_type;
	uint32_t	frame_index;
	uint32_t	*frame_instances_indices;
}	t_tile;

typedef struct s_tile_grid
{
	t_tile	***cells;
}	t_tile_grid;

typedef struct s_entity
{
	uint32_t	column_index;
	uint32_t	row_index;
	t_tile		tile;
}	t_entity;

typedef struct s_controls
{
	keys_t		up_key;
	keys_t		down_key;
	keys_t		left_key;
	keys_t		right_key;
}	t_controls;

typedef struct s_player
{
	t_entity	*entity;
	t_controls	controls;
}	t_player;

typedef struct s_data
{
	mlx_t		*mlx;
	t_grid		char_grid;
	uint32_t	scale;
	uint32_t	pixels_per_tile;
	uint32_t	window_width;
	uint32_t	window_height;
	t_texture	texture;
	uint32_t	tile_type_count;
	t_tile_type	tile_types[1 << (sizeof(char) * 8)];
	t_tile_grid	tile_grid;
	t_list		*entities;
	uint32_t	player_count;
	t_player	players[MAX_PLAYER_COUNT];
}	t_data;

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(int argc, char **argv, t_data *data);
t_status	sl_load_texture(t_data *data);
t_status	sl_instantiate_tile_types(t_data *data);
t_status	sl_instantiate_tile_grid(t_data *data);
t_status	sl_instantiate_entities(t_data *data);
t_status	sl_instantiate_players(t_data *data);
void		sl_cleanup(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
