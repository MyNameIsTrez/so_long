/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_entities.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:33:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 20:17:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_entity(void *_entity)
{
	t_entity		*entity;
	t_i32			frame_index;
	mlx_instance_t	*instance;

	entity = _entity;
	frame_index = 0;
	while (frame_index < entity->tile.tile_kind->frame_count)
	{
		instance = sl_get_frame_instance(&entity->tile, frame_index);
		instance->enabled = false;
		frame_index++;
	}
}

STATIC t_status	instantiate_entity(t_data *data)
{
	t_tile_kind			*tile_kind;
	t_entity			*entity;

	tile_kind = sl_get_character_tile_kind(data);
	entity = ft_malloc(sizeof(t_entity));
	if (entity == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (sl_fill_tile_data(&entity->tile, tile_kind, data) != OK)
		return (sl_any_error());
	if (sl_instantiate_tile_frames(&entity->tile, data) != OK)
		return (sl_any_error());
	entity->last_frame_seconds = 0;
	entity->seconds_per_frame = 0.5; // TODO: DON'T HARDCODE!!!
	if (ft_lst_new_front(&data->entities, entity) == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

STATIC t_status	try_instantiate_entity(t_data *data)
{
	if (sl_is_entity(data))
	{
		if (instantiate_entity(data) != OK)
		{
			ft_lstclear(&data->entities, free_entity);
			return (sl_any_error());
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	while (sl_iterate_char_grid(data) != FINISHED)
		if (try_instantiate_entity(data) != OK)
			return (sl_any_error());
	sl_reset_iterate_entities(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
