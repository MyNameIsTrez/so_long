/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_kinds.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 14:52:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

// STATIC void	free_all_tile_kinds(t_data *data)
// {
// 	t_tile_kind	*tile_kind;
// 	mlx_image_t	*frame;
// 	while (sl_iterate_tile_kinds(data) != FINISHED)
// 	{
// 		tile_kind = &data->it.tile_kind;
// 		while (sl_iterate_frame_count(tile_kind->frame_count, data) != FINISHED)
// 		{
// 			frame = tile_kind->frames[data->t.frame_index];
// 			if (frame != NULL)
// 				mlx_delete_image(data->mlx, frame);
// 		}
// 	}
// }

// STATIC t_status	check_tile_kind_errors(t_data *data)
// {
// 	t_tile_kind	*tile_kind;
// 	mlx_image_t	*frame;

// 	while (sl_iterate_tile_kinds(data) != FINISHED)
// 	{
// 		tile_kind = &data->it.tile_kind;
// 		while (sl_iterate_frame_count(tile_kind->frame_count, data) != FINISHED)
// 		{
// 			frame = tile_kind->frames[data->it.frame_index];
// 			if (frame == NULL)
// 			{
// 				// free_all_tile_kinds(data);
// 				return (ft_set_error(FT_ERROR_MALLOC));
// 			}
// 		}
// 	}
// 	return (OK);
// }

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

STATIC t_status	instantiate_tile_kind(t_tile_kind **tile_kind, t_data *data)
{
	*tile_kind = malloc(sizeof(t_tile_kind));
	if (*tile_kind == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (ft_lst_new_front(&data->tile_kinds, *tile_kind) == NULL)
	{
		free(*tile_kind);
		return (ft_set_error(FT_ERROR_MALLOC));
	}
	return (OK);
}

STATIC t_status	add_tile_kind(t_tile_kind_data tk_data, t_data *data)
{
	t_tile_kind	*tile_kind;
	size_t		frames_byte_count;

	instantiate_tile_kind(&tile_kind, data);
	tile_kind->character = tk_data.character;
	tile_kind->frame_count = tk_data.frame_count;
	frames_byte_count = sizeof(mlx_image_t *) * (size_t)tk_data.frame_count;
	tile_kind->frames = malloc(frames_byte_count);
	// TODO: Make sure that tile_kind is freed at the end of the program
	if (tile_kind->frames == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	// TODO: Make sure that tile_kind is freed at the end of the program
	// TODO: Make sure that tile_kind->frames is freed at the end of the program
	if (add_tile_kind_frames(tile_kind, tk_data.frame_count,
			tk_data.texture_row, data) != OK)
		return (sl_any_error());
	tile_kind->color = tk_data.color;
	return (OK);
}

STATIC t_status	add_empty_space_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){EMPTY_SPACE_TEXTURE_FRAME_COUNT,
			EMPTY_SPACE_TEXTURE_ROW, EMPTY_SPACE_CHARACTER,
			(t_tile_kind_color){(t_rgb){50, 30, 85},
		(t_rgb_step){-1, -1, -1}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_wall_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){WALL_TEXTURE_FRAME_COUNT,
			WALL_TEXTURE_ROW, WALL_CHARACTER,
			(t_tile_kind_color){(t_rgb){200, 90, 123},
		(t_rgb_step){-1, -1, -1}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_collectible_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){COLLECTIBLE_TEXTURE_FRAME_COUNT,
			COLLECTIBLE_TEXTURE_ROW, COLLECTIBLE_CHARACTER,
			(t_tile_kind_color){(t_rgb){123, 54, 18},
		(t_rgb_step){-1, -1, -1}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_map_exit_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){MAP_EXIT_TEXTURE_FRAME_COUNT,
			MAP_EXIT_TEXTURE_ROW, MAP_EXIT_CHARACTER,
			(t_tile_kind_color){(t_rgb){39, 198, 200},
		(t_rgb_step){-1, -1, -1}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_player_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){PLAYER_TEXTURE_FRAME_COUNT,
			PLAYER_TEXTURE_ROW, PLAYER_CHARACTER,
			(t_tile_kind_color){(t_rgb){104, 58, 200},
		(t_rgb_step){-1, -1, -1}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_kinds(t_data *data)
{
	if (add_empty_space_tile_kind(data) != OK)
		return (sl_any_error());
	if (add_wall_tile_kind(data) != OK)
		return (sl_any_error());
	if (add_collectible_tile_kind(data) != OK)
		return (sl_any_error());
	if (add_map_exit_tile_kind(data) != OK)
		return (sl_any_error());
	if (add_player_tile_kind(data) != OK)
		return (sl_any_error());
	// return (check_tile_kind_errors(data));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
