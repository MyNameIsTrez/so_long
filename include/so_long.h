/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/23 18:10:14 by sbos          ########   odam.nl         */
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

# define DEFAULT_SCALE 2

////////////////////////////////////////////////////////////////////////////////

# define PIXELS_PER_TILE_UNSCALED 8

////////////////////////////////////////////////////////////////////////////////

# define TEXTURE_FILENAME_SUFFIX "_pixels_per_tile.png"
# define STATIC_TEXTURE_DIR_PATH "textures/BitsyDungeonTiles/static/"
# define ANIMATED_TEXTURE_DIR_PATH "textures/BitsyDungeonTiles/animated/"

////////////////////////////////////////////////////////////////////////////////

// STATIC
# define EMPTY_SPACE_TEXTURE_COLUMN 0
# define EMPTY_SPACE_TEXTURE_ROW 0

# define WALL_TEXTURE_COLUMN 0
# define WALL_TEXTURE_ROW 0

# define COLLECTIBLE_TEXTURE_COLUMN 0
# define COLLECTIBLE_TEXTURE_ROW 0

# define MAP_EXIT_TEXTURE_COLUMN 0
# define MAP_EXIT_TEXTURE_ROW 0

// ANIMATED
# define PLAYER_TEXTURE_COLUMN 0
# define PLAYER_TEXTURE_ROW 0

////////////////////////////////////////////////////////////////////////////////

enum e_tile_textures
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
	MAP_EXIT,
	TILE_ENUM_COUNT
};

# define MAP_CHARACTERS	"01CEP"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	mlx_t		*mlx;
	t_grid		grid;
	mlx_image_t	*tile_images[TILE_ENUM_COUNT];
}	t_data;

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
