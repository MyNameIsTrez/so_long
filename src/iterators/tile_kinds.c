/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kinds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:54:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_tile_kinds(t_data *data,
								bool reset)
{
	static size_t	tile_kind_index;

	if (reset)
	{
		tile_kind_index = 0;
		return (RESET);
	}
	while (tile_kind_index < ft_vector_get_size(data->tile_kinds))
	{
		data->it.tile_kind = &data->tile_kinds[tile_kind_index];
		tile_kind_index++;
		return (LOOPED);
	}
	sl_reset_iterate_tile_kinds(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kinds(t_data *data)
{
	return (resettable_iterate_tile_kinds(data, false));
}

void	sl_reset_iterate_tile_kinds(t_data *data)
{
	resettable_iterate_tile_kinds(data, true);
}

////////////////////////////////////////////////////////////////////////////////
