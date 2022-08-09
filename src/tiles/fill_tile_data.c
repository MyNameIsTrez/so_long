/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_tile_data.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:17:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data)
{
	tile->tile_kind = tile_kind;
	tile->frame_index = 0;
	tile->frame_instances_indices = ft_vector_new(sizeof(size_t));
	if (tile->frame_instances_indices == NULL)
		return (ERROR);
	tile->column = data->it.column;
	tile->row = data->it.row;
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
