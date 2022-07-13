/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 15:12:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 15:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_is_entity(t_data *data)
{
	return (ft_chr_in_str(sl_get_char_grid_character(data), ENTITY_CHARACTERS));
}

t_status	sl_instance_tile_frames(t_tile *tile, t_data *data)
{
	int32_t				frame_instance_index;

	while (sl_iterate_frame_count(tile->tile_kind->frame_count, data) != FINISHED)
	{
		frame_instance_index = mlx_image_to_window(data->mlx,
				sl_get_frame(tile->tile_kind, data->t.frame_index),
				(int32_t)(data->texture.pixels_per_tile * data->t.column_index),
				(int32_t)(data->texture.pixels_per_tile * data->t.row_index));
		if (frame_instance_index < 0)
		{
			// TODO: Delete previous images in SL_ERROR_MLX42 cases?
			return (sl_set_error(SL_ERROR_MLX42));
		}
		tile->frame_instances_indices[data->t.frame_index] = (uint32_t)frame_instance_index;
		if (data->t.frame_index != 0)
			sl_get_instance(tile, data->t.frame_index)->enabled = false;
	}
	return (OK);
}

void	sl_shift_tile_pos(t_tile *tile, int32_t x, int32_t y, t_data *data)
{
	mlx_instance_t	*instance;

	while (sl_iterate_frame_count(tile->tile_kind->frame_count, data) != FINISHED)
	{
		instance = sl_get_instance(tile, data->t.frame_index);
		instance->x += x;
		instance->y += y;
	}
}

// void	sl_set_tile_pos(t_tile *tile, int32_t x, int32_t y, t_data *data)
// {
// 	mlx_instance_t	*instance;

// 	while (sl_iterate_frame_count(tile->tile_kind->frame_count, data) != FINISHED)
// 	{
// 		instance = sl_get_instance(tile, data->t.frame_index);
// 		instance->x = x;
// 		instance->y = y;
// 	}
// }

t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
			t_data *data)
{
	tile->tile_kind = tile_kind;
	tile->frame_index = 0;
	tile->frame_instances_indices = malloc(sizeof(uint32_t) * tile_kind->frame_count);
	if (tile->frame_instances_indices == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	tile->column_index = data->t.column_index;
	tile->row_index = data->t.row_index;
	return (OK);
}

mlx_instance_t	*sl_get_instance(t_tile *tile, uint32_t frame_index)
{
	const uint32_t		frame_instance_index = tile->frame_instances_indices[frame_index];
	const mlx_image_t	*frame = sl_get_frame(tile->tile_kind, frame_index);

	return (&frame->instances[frame_instance_index]);
}

mlx_image_t	*sl_get_frame(t_tile_kind *tile_kind, uint32_t frame_index)
{
	return (tile_kind->frames[frame_index]);
}

unsigned char	sl_get_char_grid_character(t_data *data)
{
	return ((unsigned char)data->char_grid.cells[data->t.row_index][data->t.column_index]);
}

t_tile	*sl_get_tile(t_data *data)
{
	return (data->tile_grid.cells[data->t.row_index][data->t.column_index]);
}

////////////////////////////////////////////////////////////////////////////////
