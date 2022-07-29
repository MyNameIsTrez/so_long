/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_tile_data.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:37:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data)
{
	size_t	frame_count;

	tile->tile_kind = tile_kind;
	tile->frame_index = 0;
	frame_count = tile_kind->frame_count;
	tile->frame_instances_indices = ft_malloc(frame_count, sizeof(size_t));
	if (tile->frame_instances_indices == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	tile->column_index = data->it.column_index;
	tile->row_index = data->it.row_index;
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
