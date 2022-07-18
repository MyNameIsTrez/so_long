/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_tiles.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:58:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/18 16:43:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_TILES_H
# define SL_STRUCTS_TILES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_rgb
{
	t_u8	r;
	t_u8	g;
	t_u8	b;
}	t_rgb;

typedef struct s_tile_kind_color
{
	t_u8	initial_color[3];
	t_i32	min_color[3];
	t_i32	max_color[3];
	t_i32	wait[3];
	t_i32	step[3];
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
	t_tile	**cells;
}	t_tile_grid;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
