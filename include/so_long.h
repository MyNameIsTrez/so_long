/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/17 18:00:53 by sbos          ########   odam.nl         */
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

# define WIDTH 256
# define HEIGHT 256

////////////////////////////////////////////////////////////////////////////////

enum e_tiles
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
	MAP_EXIT,
	PLAYER_STARTING_POSITION,
};

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	mlx_t		*mlx;
	// t_grid		map;
	mlx_image_t	**images;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
