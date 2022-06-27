/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/27 16:49:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SO_LONG_H
# define SO_LONG_H

////////////////////////////////////////////////////////////////////////////////

# include "MLX42/MLX42.h"

# include "libft.h"
# include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

# define TEXTUREPACK "BitsyDungeonTiles/"
# define PIXELS_PER_TILE_UNSCALED 8
# define DEFAULT_SCALE 3

////////////////////////////////////////////////////////////////////////////////

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

# define MAP_CHARACTERS	"01CEP"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_type
{
	uint32_t		frame_count;
	mlx_image_t		**frames;
}	t_tile_type;

typedef struct s_tile
{
	t_tile_type	*tile_type;
	uint32_t	frame_index;
	int32_t		*frame_instances_indices;
}	t_tile;

typedef struct s_tile_grid
{
	t_tile	***cells;
}	t_tile_grid;

typedef struct s_data
{
	mlx_t			*mlx;
	t_grid			char_grid;
	uint32_t		scale;
	uint32_t		pixels_per_tile;
	uint32_t		window_width;
	uint32_t		window_height;
	char			*texture_filename;
	mlx_texture_t	*texture;
	uint32_t		tile_type_count;
	t_tile_type		tile_types[256];
	t_tile_grid		tile_grid;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data);
t_success	sl_load_texture(t_data *data);
t_success	sl_instantiate_tile_types(t_data *data);
t_success	sl_instantiate_tile_grid(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
