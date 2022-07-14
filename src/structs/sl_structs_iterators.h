/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_iterators.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:38:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_TEMPORARY_H
# define SL_STRUCTS_TEMPORARY_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_frame_pixels
{
	t_u32	x;
	t_u32	y;
}	t_frame_pixels;

////////////////////////////////////////////////////////////////////////////////

// This struct is used for temporary ITerator data storage.
typedef struct s_it
{
	t_u32		column_index;
	t_u32		row_index;
	t_u32		frame_index;
	t_u32		player_index;
	t_u32		tile_kind_index;
	t_entity		*entity;
	keys_t			key;
	t_u8			red;
	t_frame_pixels	frame_pixels;
	t_u32		channel_index;
	t_u32		frame_byte_index;
	mlx_image_t		*frame;
}	t_it;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
