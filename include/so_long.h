/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 16:07:29 by sbos          ########   odam.nl         */
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
# define DEFAULT_SCALE 2

////////////////////////////////////////////////////////////////////////////////

# define TEXTUREPACKS_PATH "texturepacks/"
# define TEXTURES_DIR "textures/"
# define TEXTURE_SCALES_DIR "texture_scales/"
# define TEXTURE_FILENAME_PREFIX "scale_"
# define TEXTURE_FILENAME_EXTENSION ".png"

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

enum e_images
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
	MAP_EXIT,
	PLAYER,
	IMAGE_COUNT
};

# define MAP_IMAGE_CHARACTERS	"01CEP"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	mlx_t			*mlx;
	t_grid			grid;
	uint32_t		pixels_per_tile;
	uint32_t		width;
	uint32_t		height;
	char			*texture_filename;
	mlx_texture_t	*texture;
	mlx_image_t		*images[IMAGE_COUNT];
}	t_data;

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data);
t_success	sl_get_texture(t_data *data);
t_success	sl_load_images(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
