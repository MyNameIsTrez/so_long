/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_walk.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:55:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:04:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/can_walk/sl_private_tile_can_walk.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_can_walk(t_heading heading, t_tile *tile, t_data *data)
{
	size_t	index;

	if (!sl_try_get_index(&index, heading, tile, data))
		return (false);
	if (!sl_is_tile_walkable(index, data))
		return (false);
	if (is_entity_in_way(index, data))
		return (false);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
