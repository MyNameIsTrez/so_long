/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_wall_frame_index.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 13:44:57 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 14:16:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "get_wall_frame_index/sl_private_get_wall_frame_index.h"

////////////////////////////////////////////////////////////////////////////////

size_t	get_wall_frame_index(t_tile *tile, t_data *data)
{
	size_t	neighboring_walls;
	size_t	frame_index;

	neighboring_walls = get_neighboring_walls(tile, data);
	frame_index = 0;
	if (bits_are_on(neighboring_walls, 0b00000111))
		frame_index |= 1 << 0;
	if (bits_are_on(neighboring_walls, 0b00011100))
		frame_index |= 1 << 1;
	if (bits_are_on(neighboring_walls, 0b01110000))
		frame_index |= 1 << 2;
	if (bits_are_on(neighboring_walls, 0b11000001))
		frame_index |= 1 << 3;
	return (frame_index);
}

////////////////////////////////////////////////////////////////////////////////
