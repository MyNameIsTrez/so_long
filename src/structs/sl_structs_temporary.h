/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_temporary.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 13:21:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_TEMPORARY_H
# define SL_STRUCTS_TEMPORARY_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_frame_pixels
{
	uint32_t	x;
	uint32_t	y;
}	t_frame_pixels;

////////////////////////////////////////////////////////////////////////////////

// This struct is used for Temporary data storage. Used by iterators.
typedef struct s_t
{
	uint32_t		column_index;
	uint32_t		row_index;
	uint32_t		frame_index;
	uint32_t		player_index;
	uint32_t		tile_kind_index;
	t_entity		*entity;
	keys_t			key;
	uint8_t			red;
	t_frame_pixels	frame_pixels;
	uint32_t		channel_index;
}	t_t;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////