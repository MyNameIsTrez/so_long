/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/17 14:46:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"

# include "libft.h"
# include "ft_printf.h"

# define WIDTH 256
# define HEIGHT 256

enum e_tiles
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
};

typedef struct s_map
{
	int	a;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		map;
	mlx_image_t	**images;
}	t_data;

#endif
