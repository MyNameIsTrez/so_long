/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_instantiate_tile_kinds.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 17:44:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

// STATIC void	free_all_tile_kinds(t_data *data)
// {
// 	t_tile_kind	*tile_kind;
// 	mlx_image_t	*frame;

// 	while (sl_iterate_tile_kind_count(data) != FINISHED)
// 	{
// 		tile_kind = &data->tile_kinds[data->t.tile_kind_index];
// 		while (sl_iterate_frame_count(tile_kind->frame_count, data) != FINISHED)
// 		{
// 			frame = tile_kind->frames[data->t.frame_index];
// 			if (frame != NULL)
// 				mlx_delete_image(data->mlx, frame);
// 		}
// 	}
// }

STATIC t_status	check_tile_kind_errors(t_data *data)
{
	t_tile_kind	*tile_kind;
	mlx_image_t	*frame;

	while (sl_iterate_tile_kind_count(data) != FINISHED)
	{
		tile_kind = &data->tile_kinds[data->it.tile_kind_index];
		while (sl_iterate_frame_count(tile_kind->frame_count, data) != FINISHED)
		{
			frame = tile_kind->frames[data->it.frame_index];
			if (frame == NULL)
			{
				// free_all_tile_kinds(data);
				return (ft_set_error(FT_ERROR_MALLOC));
			}
		}
	}
	return (OK);
}

STATIC t_status	add_tile_kind_frames(t_tile_kind *tile_kind, t_i32 frame_count,
			t_i32 texture_row, t_data *data)
{
	t_i32	pixels_per_tile;
	t_i32	frame_index;
	t_u32	wh[2];
	t_u32	xy[2];

	pixels_per_tile = data->texture.pixels_per_tile;
	wh[0] = (t_u32)pixels_per_tile;
	wh[1] = (t_u32)pixels_per_tile;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		frame_index = data->it.frame_index;
		xy[0] = (t_u32)(pixels_per_tile * frame_index);
		xy[1] = (t_u32)(pixels_per_tile * texture_row);
		tile_kind->frames[frame_index] = mlx_texture_area_to_image(data->mlx,
				data->texture.data, xy, wh);
		if (tile_kind->frames[frame_index] == NULL)
			return (sl_set_error(SL_ERROR_MLX42));
	}
	return (OK);
}

STATIC t_status	add_tile_kind(t_i32 frame_count, t_i32 texture_row,
			t_u8 grid_character, t_data *data)
{
	t_tile_kind	*tile_kind;

	tile_kind = &data->tile_kinds[grid_character];
	tile_kind->character = grid_character;
	tile_kind->frame_count = frame_count;
	tile_kind->frames = malloc(sizeof(mlx_image_t *) * (size_t)frame_count);
	if (tile_kind->frames == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (add_tile_kind_frames(tile_kind, frame_count, texture_row, data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC void	calculate_tile_kind_count(t_data *data)
{
	data->tile_kind_count = (t_i32)ft_strlen(MAP_CHARACTERS);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_kinds(t_data *data)
{
	calculate_tile_kind_count(data);
	if (add_tile_kind(EMPTY_SPACE_TEXTURE_FRAME_COUNT, EMPTY_SPACE_TEXTURE_ROW,
			EMPTY_SPACE_CHARACTER, data) != OK)
		return (sl_any_error());
	if (add_tile_kind(WALL_TEXTURE_FRAME_COUNT, WALL_TEXTURE_ROW,
			WALL_CHARACTER, data) != OK)
		return (sl_any_error());
	if (add_tile_kind(COLLECTIBLE_TEXTURE_FRAME_COUNT, COLLECTIBLE_TEXTURE_ROW,
			COLLECTIBLE_CHARACTER, data) != OK)
		return (sl_any_error());
	if (add_tile_kind(MAP_EXIT_TEXTURE_FRAME_COUNT, MAP_EXIT_TEXTURE_ROW,
			MAP_EXIT_CHARACTER, data) != OK)
		return (sl_any_error());
	if (add_tile_kind(PLAYER_TEXTURE_FRAME_COUNT, PLAYER_TEXTURE_ROW,
			PLAYER_CHARACTER, data) != OK)
		return (sl_any_error());
	return (check_tile_kind_errors(data));
}

////////////////////////////////////////////////////////////////////////////////
