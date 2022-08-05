/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_entity.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:02:04 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 21:00:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_entity(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_entity	entity;

	tile_kind = sl_get_character_tile_kind(data);
	if (sl_fill_tile_data(&entity.tile, tile_kind, data) != OK)
		return (ERROR);
	if (sl_instantiate_tile_frames(&entity.tile, data) != OK)
		return (ERROR);
	entity.ticks_since_last_frame_change = 0;
	entity.ticks_between_frame_changes = 30; // TODO: Don't hardcode
	if (ft_vector_push(&data->entities, &entity) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////