/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/16 13:15:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"

# include "libft.h"

# define WIDTH 256
# define HEIGHT 256

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	**images;
}	t_data;

#endif
