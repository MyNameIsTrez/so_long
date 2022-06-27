/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_instantiate_tile_types.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/27 13:00:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_all_tile_types(t_data *data)
{
	uint32_t	tile_type_index;
	t_tile_type	*tile_type;
	uint32_t	frame_index;
	mlx_image_t	*frame;

	tile_type_index = 0;
	while (tile_type_index < data->tile_type_count)
	{
		tile_type = &data->tile_types[tile_type_index];
		frame_index = 0;
		while (frame_index < tile_type->frame_count)
		{
			frame = tile_type->frames[frame_index];
			if (frame != NULL)
				mlx_delete_image(data->mlx, frame);
			frame_index++;
		}
		tile_type_index++;
	}
}

STATIC t_success	check_tile_type_errors(t_data *data)
{
	uint32_t	tile_type_index;
	t_tile_type	*tile_type;
	uint32_t	frame_index;
	mlx_image_t	*frame;

	tile_type_index = 0;
	while (tile_type_index < data->tile_type_count)
	{
		tile_type = &data->tile_types[tile_type_index];
		frame_index = 0;
		while (frame_index < tile_type->frame_count)
		{
			frame = tile_type->frames[frame_index];
			if (frame == NULL)
			{
				free_all_tile_types(data);
				return (ft_set_error(ERROR_MALLOC));
			}
			frame_index++;
		}
		tile_type_index++;
	}
	return (SUCCESS);
}

STATIC void	add_tile_type(uint32_t frame_count, uint32_t texture_row,
			char grid_character, t_data *data)
{
	t_tile_type*const	tile_type = &data->tile_types[(unsigned char)grid_character];
	uint32_t			frame_index;

	tile_type->frame_count = frame_count;
	tile_type->frames = malloc(sizeof(mlx_image_t *) * frame_count);
	frame_index = 0;
	while (frame_index < frame_count)
	{
		tile_type->frames[frame_index] = mlx_texture_area_to_image(data->mlx,
				data->texture,
				(uint32_t[2]){
				data->pixels_per_tile * frame_index,
				data->pixels_per_tile * texture_row},
				(uint32_t[2]){data->pixels_per_tile, data->pixels_per_tile});
		frame_index++;
	}
}

STATIC void	calculate_tile_type_count(t_data *data)
{
	data->tile_type_count = (uint32_t)ft_strlen(MAP_CHARACTERS);
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_instantiate_tile_types(t_data *data)
{
	calculate_tile_type_count(data);
	add_tile_type(EMPTY_SPACE_TEXTURE_FRAME_COUNT, EMPTY_SPACE_TEXTURE_ROW,
		EMPTY_SPACE_CHARACTER, data);
	add_tile_type(WALL_TEXTURE_FRAME_COUNT, WALL_TEXTURE_ROW,
		WALL_CHARACTER, data);
	add_tile_type(COLLECTIBLE_TEXTURE_FRAME_COUNT, COLLECTIBLE_TEXTURE_ROW,
		COLLECTIBLE_CHARACTER, data);
	add_tile_type(MAP_EXIT_TEXTURE_FRAME_COUNT, MAP_EXIT_TEXTURE_ROW,
		MAP_EXIT_CHARACTER, data);
	add_tile_type(PLAYER_TEXTURE_FRAME_COUNT, PLAYER_TEXTURE_ROW,
		PLAYER_CHARACTER, data);
	mlx_delete_texture(data->texture);
	return (check_tile_type_errors(data));
}

////////////////////////////////////////////////////////////////////////////////
