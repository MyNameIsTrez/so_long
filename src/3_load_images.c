/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_load_images.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 17:35:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_all_images(t_data *data)
{
	uint32_t	tile_index;

	tile_index = 0;
	while (tile_index < data->image_count)
	{
		if (data->images[tile_index] != NULL)
			mlx_delete_image(data->mlx, data->images[tile_index]);
		tile_index++;
	}
}

STATIC t_success	check_image_errors(t_data *data)
{
	uint32_t	tile_index;

	tile_index = 0;
	while (tile_index < data->image_count)
	{
		if (data->images[tile_index] == NULL)
		{
			free_all_images(data);
			return (ft_set_error(ERROR_MALLOC));
		}
		tile_index++;
	}
	return (SUCCESS);
}

STATIC void	load_tile_images(uint32_t frame_count, uint32_t texture_row,
			t_data *data)
{
	uint32_t	frame_index;
	static int	image_index;

	frame_index = 0;
	while (frame_index < frame_count)
	{
		data->images[image_index] = mlx_texture_area_to_image(data->mlx,
				data->texture,
				(uint32_t[2]){frame_index * data->pixels_per_tile,
				texture_row * data->pixels_per_tile},
				(uint32_t[2]){data->pixels_per_tile, data->pixels_per_tile});
		image_index++;
		frame_index++;
	}
}

STATIC t_success	malloc_images(t_data *data)
{
	data->images = malloc(data->image_count);
	if (data->images == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

STATIC void	calculate_image_count(t_data *data)
{
	data->image_count = 0
		+ EMPTY_SPACE_TEXTURE_FRAME_COUNT
		+ WALL_TEXTURE_FRAME_COUNT
		+ COLLECTIBLE_TEXTURE_FRAME_COUNT
		+ MAP_EXIT_TEXTURE_FRAME_COUNT
		+ PLAYER_TEXTURE_FRAME_COUNT
		;
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_load_images(t_data *data)
{
	calculate_image_count(data);
	if (malloc_images(data) != SUCCESS)
		return (ft_get_error());
	load_tile_images(EMPTY_SPACE_TEXTURE_FRAME_COUNT, EMPTY_SPACE_TEXTURE_ROW,
		data);
	load_tile_images(WALL_TEXTURE_FRAME_COUNT, WALL_TEXTURE_ROW,
		data);
	load_tile_images(COLLECTIBLE_TEXTURE_FRAME_COUNT, COLLECTIBLE_TEXTURE_ROW,
		data);
	load_tile_images(MAP_EXIT_TEXTURE_FRAME_COUNT, MAP_EXIT_TEXTURE_ROW,
		data);
	load_tile_images(PLAYER_TEXTURE_FRAME_COUNT, PLAYER_TEXTURE_ROW,
		data);
	mlx_delete_texture(data->texture);
	return (check_image_errors(data));
}

////////////////////////////////////////////////////////////////////////////////
