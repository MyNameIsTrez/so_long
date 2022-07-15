/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_tiles.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:58:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 13:39:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_TILES_H
# define SL_STRUCTS_TILES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_color_step
{
	t_i32	r;
	t_i32	g;
	t_i32	b;
}	t_color_step;

typedef struct s_tile_kind_color
{
	t_color_step	step;
}	t_tile_kind_color;

typedef struct s_tile_kind
{
	t_u8				character;
	t_i32				frame_count;
	mlx_image_t			**frames;
	t_tile_kind_color	color;
}	t_tile_kind;

typedef struct s_tile
{
	t_tile_kind	*tile_kind;
	t_i32		frame_index;
	t_i32		*frame_instances_indices;
	t_i32		column_index;
	t_i32		row_index;
}	t_tile;

typedef struct s_tile_grid
{
	t_tile	***cells;
}	t_tile_grid;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
