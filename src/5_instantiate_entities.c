/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5_instantiate_entities.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:33:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 18:23:18 by sbos          ########   odam.nl         */
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

STATIC t_status	instantiate_entity(uint32_t column_index,
			uint32_t row_index, t_data *data)
{
	const unsigned char	grid_character = sl_get_grid_character(column_index,
			row_index, data);
	t_tile_kind			*tile_kind;
	t_entity			*entity;

	tile_kind = &data->tile_kinds[grid_character];
	entity = malloc(sizeof(t_entity));
	if (entity == NULL)
		return (ft_set_error(ERROR_MALLOC));
	entity->column_index = column_index;
	entity->row_index = row_index;
	if (sl_fill_tile_data(tile_kind, &entity->tile) != OK)
		return (ft_get_error());
	if (sl_initialize_instance_for_frames(&entity->tile, entity->column_index,
			entity->row_index, data) != OK)
		return (ft_get_error());
	if (ft_lst_new_front(&data->entities, entity) == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (OK);
}

STATIC t_status	callback_instantiate_entity(uint32_t column_index,
			uint32_t row_index, t_data *data)
{
	if (sl_is_entity(column_index, row_index, data))
	{
		if (instantiate_entity(column_index, row_index, data) != OK)
		{
			ft_lstclear(&data->entities, free_entity);
			return (ft_get_error());
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	if (sl_iterate_char_grid(callback_instantiate_entity, data) != OK)
		return (ft_get_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
