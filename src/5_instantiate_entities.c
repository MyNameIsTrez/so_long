/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5_instantiate_entities.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:33:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 14:57:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_entity(void *_entity)
{
	t_entity		*entity;
	uint32_t		frame_index;
	mlx_instance_t	*instance;

	entity = _entity;
	frame_index = 0;
	while (frame_index < entity->tile.tile_kind->frame_count)
	{
		instance = sl_get_instance(&entity->tile, frame_index);
		instance->enabled = false;
		frame_index++;
	}
}

STATIC t_status	instantiate_entity(t_data *data)
{
	t_tile_kind			*tile_kind;
	t_entity			*entity;

	tile_kind = &data->tile_kinds[sl_get_grid_character(data)];
	entity = malloc(sizeof(t_entity));
	if (entity == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	entity->column_index = data->t.column_index;
	entity->row_index = data->t.row_index;
	if (sl_fill_tile_data(tile_kind, &entity->tile) != OK)
		return (sl_any_error());
	if (sl_instance_tile_frames(&entity->tile, data) != OK)
		return (sl_any_error());
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
	sl_iterate_char_grid(data, true);
	while (sl_iterate_char_grid(data, false) != FINISHED)
		if (try_instantiate_entity(data) != OK)
			return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
