/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_load_images.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 16:09:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_all_images(t_data *data)
{
	int	tile_index;

	tile_index = 0;
	while (tile_index < IMAGE_COUNT)
	{
		if (data->images[tile_index] != NULL)
			mlx_delete_image(data->mlx, data->images[tile_index]);
		tile_index++;
	}
}

STATIC t_success	check_image_errors(t_data *data)
{
	int	tile_index;

	tile_index = 0;
	while (tile_index < IMAGE_COUNT)
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

STATIC void	load_image(uint32_t column, uint32_t row, t_data *data)
{
	static int				image_index;

	data->images[image_index] = mlx_texture_area_to_image(data->mlx,
			data->texture,
			(uint32_t[2]){column, row},
			(uint32_t[2]){data->pixels_per_tile, data->pixels_per_tile});
	image_index++;
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_load_images(t_data *data)
{
	load_image(EMPTY_SPACE_TEXTURE_ROW, EMPTY_SPACE_TEXTURE_COLUMN, data);
	load_image(WALL_TEXTURE_ROW, WALL_TEXTURE_COLUMN, data);
	load_image(COLLECTIBLE_TEXTURE_ROW, COLLECTIBLE_TEXTURE_COLUMN, data);
	load_image(MAP_EXIT_TEXTURE_ROW, MAP_EXIT_TEXTURE_COLUMN, data);
	// TODO: Load the two textures of an animated texture, instead of just one.
	load_image(PLAYER_TEXTURE_ROW, PLAYER_TEXTURE_COLUMN, data);
	mlx_delete_texture(data->texture);
	return (check_image_errors(data));
}

////////////////////////////////////////////////////////////////////////////////
