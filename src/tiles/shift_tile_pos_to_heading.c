/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_tile_pos_to_heading.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:08:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Only call this function when it'll be in bounds.
 *
 * @param tile
 * @param heading
 * @param data
 */
void	sl_shift_tile_pos_to_heading(t_tile *tile, t_heading heading,
			t_data *data)
{
	sl_set_tile_pos(tile, sl_get_heading_index(heading, tile, data), data);
}

////////////////////////////////////////////////////////////////////////////////
