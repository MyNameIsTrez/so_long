/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_struct_iterators.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 17:51:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCT_ITERATORS_H
# define SL_STRUCT_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../players/sl_struct_player.h"
# include "../entities/sl_struct_entity.h"
# include "../tile_kinds/sl_struct_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_frame_pixels
{
	size_t	x;
	size_t	y;
}	t_frame_pixels;

////////////////////////////////////////////////////////////////////////////////

// This struct is used for temporary ITerator data storage
typedef struct s_it
{
	size_t			column_index;
	size_t			row_index;
	size_t			frame_index;
	t_player		*player;
	t_entity		*entity;
	keys_t			key;
	t_u8			red;
	t_frame_pixels	frame_pixels;
	size_t			rgb_channel_index;
	mlx_image_t		*frame;
	t_tile_kind		*tile_kind;
	size_t			pixel_index;
	keys_t			player_movement_key;
}	t_it;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////