/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_struct_tile_kind.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 17:50:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 14:32:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCT_TILE_KIND_H
# define SL_STRUCT_TILE_KIND_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind_color
{
	t_u8	initial_color[3];
	t_u8	min_color[3];
	t_u8	max_color[3];
	t_u32	wait[3];
	t_i32	step[3];
}	t_tile_kind_color;

typedef struct s_tile_kind
{
	t_u8				character;
	bool				is_entity;
	size_t				frame_count;
	mlx_image_t			**frames;
	t_u8				**original_frames_pixels;
	t_i32				depth;
	t_tile_kind_color	color;
}	t_tile_kind;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
