/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 20:26:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC mlx_image_t	*get_image(uint32_t column, uint32_t row,
			uint32_t frame_index, t_data *data)
{
	const unsigned char	grid_character = data->char_grid.cells[row][column];
	const t_tile_type	*tile_type = &data->tile_types[grid_character];

	return (tile_type->frames[frame_index]);
}

STATIC t_tile	*get_malloced_tile(uint32_t column, uint32_t row,
			t_data *data)
{
	const unsigned char	grid_character = data->char_grid.cells[row][column];
	t_tile				*tile;
	t_tile_type			*tile_type;

	tile = malloc(sizeof(t_tile));
	tile_type = &data->tile_types[grid_character];
	tile->tile_type = tile_type;
	tile->frame_index = 0;
	return (tile);
}

STATIC t_success	instantiate_tile(uint32_t column, uint32_t row,
			t_data *data)
{
	uint32_t		frame_index;
	t_tile*const	tile = get_malloced_tile(column, row, data);
	const uint32_t	frame_count = tile->tile_type->frame_count;

	frame_index = 0;
	while (frame_index < frame_count)
	{
		if (mlx_image_to_window(data->mlx,
				get_image(column, row, frame_index, data), // TODO: Should this function ever be checked for an error?
				(int32_t)(data->pixels_per_tile * column),
				(int32_t)(data->pixels_per_tile * row)) == -1)
		{
			// TODO: Delete previous images in ERROR_MLX42 cases?
			return (ft_set_error(ERROR_MLX42));
		}
		frame_index++;
	}
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

/* TODO:
 * Is this snippet from MLX42.h line 620 saying that doing
 * data->images->instances[n] could fail?
 *
 * NOTE: Keep in mind that the instance array gets reallocated, try to
 * to store the return value to the instance!
 * NOT the pointer! It will become invalid!
 */
t_success	sl_instantiate_tile_grid(t_data *data)
{
	uint32_t	column;
	uint32_t	row;

	row = 0;
	while (row < data->char_grid.height)
	{
		column = 0;
		while (column < data->char_grid.width)
		{
			instantiate_tile(column, row, data);
			column++;
		}
		row++;
	}
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
