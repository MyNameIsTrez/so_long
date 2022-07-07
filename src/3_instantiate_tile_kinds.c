/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_instantiate_tile_types.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 14:57:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_all_tile_kinds(t_data *data)
{
	uint32_t	tile_kind_index;
	t_tile_kind	*tile_kind;
	uint32_t	frame_index;
	mlx_image_t	*frame;

	tile_kind_index = 0;
	while (tile_kind_index < data->tile_kind_count)
	{
		tile_kind = &data->tile_kinds[tile_kind_index];
		frame_index = 0;
		while (frame_index < tile_kind->frame_count)
		{
			frame = tile_kind->frames[frame_index];
			if (frame != NULL)
				mlx_delete_image(data->mlx, frame);
			frame_index++;
		}
		tile_kind_index++;
	}
}

STATIC t_status	check_tile_kind_errors(t_data *data)
{
	uint32_t	tile_kind_index;
	t_tile_kind	*tile_kind;
	uint32_t	frame_index;
	mlx_image_t	*frame;

	tile_kind_index = 0;
	while (tile_kind_index < data->tile_kind_count)
	{
		tile_kind = &data->tile_kinds[tile_kind_index];
		frame_index = 0;
		while (frame_index < tile_kind->frame_count)
		{
			frame = tile_kind->frames[frame_index];
			if (frame == NULL)
			{
				free_all_tile_kinds(data);
				return (ft_set_error(FT_ERROR_MALLOC));
			}
			frame_index++;
		}
		tile_kind_index++;
	}
	return (OK);
}

STATIC void	add_tile_kind(uint32_t frame_count, uint32_t texture_row,
			unsigned char grid_character, t_data *data)
{
	t_tile_kind*const	tile_kind = &data->tile_kinds[grid_character];
	uint32_t			frame_index;

	tile_kind->character = grid_character;
	tile_kind->frame_count = frame_count;
	tile_kind->frames = malloc(sizeof(mlx_image_t *) * frame_count);
	// TODO: check malloc fail
	frame_index = 0;
	while (frame_index < frame_count)
	{
		tile_kind->frames[frame_index] = mlx_texture_area_to_image(data->mlx,
				data->texture.data,
				(uint32_t[2]){
				data->texture.pixels_per_tile * frame_index,
				data->texture.pixels_per_tile * texture_row},
				(uint32_t[2]){data->texture.pixels_per_tile, data->texture.pixels_per_tile});
		frame_index++;
	}
}

STATIC void	calculate_tile_kind_count(t_data *data)
{
	data->tile_kind_count = (uint32_t)ft_strlen(MAP_CHARACTERS);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_kinds(t_data *data)
{
	calculate_tile_kind_count(data);
	add_tile_kind(EMPTY_SPACE_TEXTURE_FRAME_COUNT, EMPTY_SPACE_TEXTURE_ROW,
		EMPTY_SPACE_CHARACTER, data);
	add_tile_kind(WALL_TEXTURE_FRAME_COUNT, WALL_TEXTURE_ROW,
		WALL_CHARACTER, data);
	add_tile_kind(COLLECTIBLE_TEXTURE_FRAME_COUNT, COLLECTIBLE_TEXTURE_ROW,
		COLLECTIBLE_CHARACTER, data);
	add_tile_kind(MAP_EXIT_TEXTURE_FRAME_COUNT, MAP_EXIT_TEXTURE_ROW,
		MAP_EXIT_CHARACTER, data);
	add_tile_kind(PLAYER_TEXTURE_FRAME_COUNT, PLAYER_TEXTURE_ROW,
		PLAYER_CHARACTER, data);
	return (check_tile_kind_errors(data));
}

////////////////////////////////////////////////////////////////////////////////
