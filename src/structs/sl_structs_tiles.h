/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_tiles.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:58:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 14:04:13 by sbos          ########   odam.nl         */
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
	size_t				frame_count;
	mlx_image_t			**frames;
	t_tile_kind_color	color;
}	t_tile_kind;

typedef struct s_tile
{
	t_tile_kind	*tile_kind;
	size_t		frame_index;
	size_t		*frame_instances_indices;
	size_t		column_index;
	size_t		row_index;
}	t_tile;

typedef struct s_tile_grid
{
	t_tile	**cells;
}	t_tile_grid;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
