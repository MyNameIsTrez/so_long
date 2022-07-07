/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kind_count.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:26:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 15:29:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kind_count(t_data *data)
{
	while (data->t.it.tile_kind_index < data->tile_kind_count)
	{
		data->t.tile_kind_index = data->t.it.tile_kind_index;
		data->t.it.tile_kind_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_tile_kind_count(t_data *data)
{
	data->t.it.tile_kind_index = 0;
}

////////////////////////////////////////////////////////////////////////////////
