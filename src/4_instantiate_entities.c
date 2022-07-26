/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_entities.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:33:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 11:01:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	instantiate_entity(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_entity	entity;

	tile_kind = sl_get_character_tile_kind(data);
	if (sl_fill_tile_data(&entity.tile, tile_kind, data) != OK)
		return (sl_any_error());
	if (sl_instantiate_tile_frames(&entity.tile, data) != OK)
		return (sl_any_error());
	entity.last_frame_seconds = 0;
	entity.seconds_per_frame = 0.5; // TODO: Don't hardcode
	if (ft_vector_push(&data->entities, &entity) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	try_instantiate_entity(t_data *data)
{
	if (sl_is_entity(data) && instantiate_entity(data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	data->entities = ft_vector_new(sizeof(t_entity));
	while (sl_iterate_char_grid(data) != FINISHED)
		if (try_instantiate_entity(data) != OK)
			return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
