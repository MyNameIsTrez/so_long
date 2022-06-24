/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 17:39:04 by sbos          ########   odam.nl         */
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
# define EMPTY_SPACE_TEXTURE_FRAME_COUNT 1
# define EMPTY_SPACE_TEXTURE_ROW 0

# define WALL_TEXTURE_FRAME_COUNT 1
# define WALL_TEXTURE_ROW 1

# define COLLECTIBLE_TEXTURE_FRAME_COUNT 1
# define COLLECTIBLE_TEXTURE_ROW 43

# define MAP_EXIT_TEXTURE_FRAME_COUNT 1
# define MAP_EXIT_TEXTURE_ROW 18

// ANIMATED
# define PLAYER_TEXTURE_FRAME_COUNT 1
# define PLAYER_TEXTURE_ROW 25

////////////////////////////////////////////////////////////////////////////////

# define MAP_CHARACTERS	"01CEP"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	mlx_t			*mlx;
	t_grid			grid;
	uint32_t		scale;
	uint32_t		pixels_per_tile;
	uint32_t		width;
	uint32_t		height;
	char			*texture_filename;
	mlx_texture_t	*texture;
	uint32_t		image_count;
	mlx_image_t		**images;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data);
t_success	sl_load_texture(t_data *data);
t_success	sl_load_images(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
