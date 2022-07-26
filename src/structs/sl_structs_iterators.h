/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_iterators.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 16:39:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_ITERATORS_H
# define SL_STRUCTS_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_frame_pixels
{
	t_i32	x;
	t_i32	y;
}	t_frame_pixels;

////////////////////////////////////////////////////////////////////////////////

// This struct is used for temporary ITerator data storage
typedef struct s_it
{
	t_i32			column_index;
	t_i32			row_index;
	t_i32			frame_index;
	t_player		*player;
	t_entity		*entity;
	keys_t			key;
	t_u8			red;
	t_frame_pixels	frame_pixels;
	t_i32			rgb_channel_index;
	mlx_image_t		*frame;
	t_tile_kind		*tile_kind;
	t_i32			pixel_index;
	keys_t			player_movement_key;
}	t_it;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
