/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tiles.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:58:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 18:24:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILES_H
# define SL_TILES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind
{
	unsigned char	character;
	uint32_t		frame_count;
	mlx_image_t		**frames;
}	t_tile_kind;

typedef struct s_tile
{
	t_tile_kind	*tile_kind;
	uint32_t	frame_index;
	uint32_t	*frame_instances_indices;
}	t_tile;

typedef struct s_tile_grid
{
	t_tile	***cells;
}	t_tile_grid;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
