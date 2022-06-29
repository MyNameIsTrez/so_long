/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5_instantiate_entities.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:33:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 12:52:02 by sbos          ########   odam.nl         */
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
	while (frame_index < entity->tile.tile_type->frame_count)
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
	t_tile_type			*tile_type;
	t_entity			*entity;

	tile_type = &data->tile_types[grid_character];
	entity = malloc(sizeof(t_entity));
	if (entity == NULL)
		return (ft_set_error(ERROR_MALLOC));
	entity->column_index = column_index;
	entity->row_index = row_index;
	if (sl_fill_tile_data(tile_type, &entity->tile) != OK)
		return (ft_get_error());
	if (sl_initialize_instance_for_frames(&entity->tile, entity->column_index,
			entity->row_index, data) != OK)
		return (ft_get_error());
	if (ft_lst_new_front(&data->entities, entity) == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	uint32_t	column_index;
	uint32_t	row_index;

	row_index = 0;
	while (row_index < data->char_grid.height)
	{
		column_index = 0;
		while (column_index < data->char_grid.width)
		{
			if (is_entity(column_index, row_index, data))
			{
				if (instantiate_entity(column_index, row_index,
						data) != OK)
				{
					ft_lstclear(&data->entities, free_entity);
					return (ft_get_error());
				}
			}
			column_index++;
		}
		row_index++;
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
