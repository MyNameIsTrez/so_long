/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_kinds.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 21:48:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

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
	*tile_kind = ft_malloc(1, sizeof(t_tile_kind));
	if (*tile_kind == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (ft_lst_new_front(&data->tile_kinds, *tile_kind) == NULL)
	{
		ft_free(tile_kind);
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
	tile_kind->frames = ft_malloc(frames_byte_count, sizeof(mlx_image_t *));
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
	if (add_tile_kind((t_tile_kind_data){
			EMPTY_SPACE_TEXTURE_FRAME_COUNT,
			EMPTY_SPACE_TEXTURE_ROW,
			EMPTY_SPACE_CHARACTER,
			(t_tile_kind_color){
			{EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
			{EMPTY_SPACE_MIN_R, EMPTY_SPACE_MIN_G, EMPTY_SPACE_MIN_B},
			{EMPTY_SPACE_MAX_R, EMPTY_SPACE_MAX_G, EMPTY_SPACE_MAX_B},
			{EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
			{EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_wall_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			WALL_TEXTURE_FRAME_COUNT,
			WALL_TEXTURE_ROW,
			WALL_CHARACTER,
			(t_tile_kind_color){
			{WALL_R, WALL_G, WALL_B},
			{WALL_MIN_R, WALL_MIN_G, WALL_MIN_B},
			{WALL_MAX_R, WALL_MAX_G, WALL_MAX_B},
			{WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
			{WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_collectible_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			COLLECTIBLE_TEXTURE_FRAME_COUNT,
			COLLECTIBLE_TEXTURE_ROW,
			COLLECTIBLE_CHARACTER,
			(t_tile_kind_color){
			{COLLECTIBLE_R, COLLECTIBLE_G, COLLECTIBLE_B},
			{COLLECTIBLE_MIN_R, COLLECTIBLE_MIN_G, COLLECTIBLE_MIN_B},
			{COLLECTIBLE_MAX_R, COLLECTIBLE_MAX_G, COLLECTIBLE_MAX_B},
			{COLLECTIBLE_R_WAIT, COLLECTIBLE_G_WAIT, COLLECTIBLE_B_WAIT},
			{COLLECTIBLE_R_STEP, COLLECTIBLE_G_STEP, COLLECTIBLE_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_map_exit_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			MAP_EXIT_TEXTURE_FRAME_COUNT,
			MAP_EXIT_TEXTURE_ROW,
			MAP_EXIT_CHARACTER,
			(t_tile_kind_color){
			{MAP_EXIT_R, MAP_EXIT_G, MAP_EXIT_B},
			{MAP_EXIT_MIN_R, MAP_EXIT_MIN_G, MAP_EXIT_MIN_B},
			{MAP_EXIT_MAX_R, MAP_EXIT_MAX_G, MAP_EXIT_MAX_B},
			{MAP_EXIT_R_WAIT, MAP_EXIT_G_WAIT, MAP_EXIT_B_WAIT},
			{MAP_EXIT_R_STEP, MAP_EXIT_G_STEP, MAP_EXIT_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

STATIC t_status	add_player_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			PLAYER_TEXTURE_FRAME_COUNT,
			PLAYER_TEXTURE_ROW,
			PLAYER_CHARACTER,
			(t_tile_kind_color){
			{PLAYER_R, PLAYER_G, PLAYER_B},
			{PLAYER_MIN_R, PLAYER_MIN_G, PLAYER_MIN_B},
			{PLAYER_MAX_R, PLAYER_MAX_G, PLAYER_MAX_B},
			{PLAYER_R_WAIT, PLAYER_G_WAIT, PLAYER_B_WAIT},
			{PLAYER_R_STEP, PLAYER_G_STEP, PLAYER_B_STEP}}},
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
	sl_reset_iterate_tile_kinds(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
