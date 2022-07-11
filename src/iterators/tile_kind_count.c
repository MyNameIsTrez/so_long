/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kind_count.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:26:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 14:55:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_tile_kind_count(t_data *data,
			bool reset)
{
	static uint32_t	tile_kind_index;

	if (reset)
	{
		tile_kind_index = 0;
		data->t.tile_kind_index = 0;
		return (RESET);
	}
	while (tile_kind_index < data->tile_kind_count)
	{
		data->t.tile_kind_index = tile_kind_index;
		tile_kind_index++;
		return (LOOPED);
	}
	sl_reset_iterate_tile_kind_count(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kind_count(t_data *data)
{
	return (resettable_iterate_tile_kind_count(data, false));
}

void	sl_reset_iterate_tile_kind_count(t_data *data)
{
	resettable_iterate_tile_kind_count(data, true);
}

////////////////////////////////////////////////////////////////////////////////
