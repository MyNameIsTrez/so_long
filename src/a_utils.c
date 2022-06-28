/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 15:12:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/28 16:46:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_entity(uint32_t column_index, uint32_t row_index, t_data *data)
{
	const unsigned char	grid_character = sl_get_grid_character(column_index,
			row_index, data);

	return (ft_chr_in_str(grid_character, ENTITY_CHARACTERS));
}

t_success	sl_initialize_instance_for_frames(t_tile *tile,
			uint32_t column_index, uint32_t row_index, t_data *data)
{
	t_tile_type	*tile_type;
	uint32_t	frame_count;
	uint32_t	frame_index;
	int32_t		frame_instance_index;

	tile_type = tile->tile_type;
	frame_count = tile_type->frame_count;
	frame_index = 0;
	while (frame_index < frame_count)
	{
		frame_instance_index = mlx_image_to_window(data->mlx,
				sl_get_frame(tile_type, frame_index),
				(int32_t)(data->pixels_per_tile * column_index),
				(int32_t)(data->pixels_per_tile * row_index));
		if (frame_instance_index < 0)
		{
			// TODO: Delete previous images in ERROR_MLX42 cases?
			return (ft_set_error(ERROR_MLX42));
		}
		tile->frame_instances_indices[frame_index] = (uint32_t)frame_instance_index;
		if (frame_index != 0)
			sl_get_instance(tile, frame_index)->enabled = false;
		frame_index++;
	}
	return (SUCCESS);
}

void	sl_shift_tile_pos(t_tile *tile, int32_t x, int32_t y)
{
	mlx_instance_t	*instance;

	instance = sl_get_instance(tile, tile->frame_index);
	instance->x += x;
	instance->y += y;
}

void	sl_set_tile_pos(t_tile *tile, int32_t x, int32_t y)
{
	mlx_instance_t	*instance;

	instance = sl_get_instance(tile, tile->frame_index);
	instance->x = x;
	instance->y = y;
}

t_success	sl_fill_tile_data(t_tile_type *tile_type, t_tile *tile)
{
	tile->tile_type = tile_type;
	tile->frame_index = 0;
	tile->frame_instances_indices = malloc(sizeof(uint32_t) * tile_type->frame_count);
	if (tile->frame_instances_indices == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

mlx_instance_t	*sl_get_instance(t_tile *tile, uint32_t frame_index)
{
	const uint32_t		frame_instance_index = tile->frame_instances_indices[frame_index];
	const mlx_image_t	*frame = sl_get_frame(tile->tile_type, frame_index);

	return (&frame->instances[frame_instance_index]);
}

mlx_image_t	*sl_get_frame(t_tile_type *tile_type, uint32_t frame_index)
{
	return (tile_type->frames[frame_index]);
}

unsigned char	sl_get_grid_character(uint32_t column_index, uint32_t row_index,
			t_data *data)
{
	return ((unsigned char)data->char_grid.cells[row_index][column_index]);
}

////////////////////////////////////////////////////////////////////////////////
