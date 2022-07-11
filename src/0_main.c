/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 13:54:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

// TODO: remove
// __attribute__((deconstructor))
// __attribute__((destructor))
void	check_leaks(void)
{
	ft_putendl("");
	system("leaks -q so_long");
}

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_frames(t_data *data)
{
	t_entity	*entity;
	t_tile		*tile;

	while (sl_iterate_entities(data) != FINISHED)
	{
		entity = data->t.entity;
		tile = &entity->tile;
		if (data->seconds - entity->last_frame_seconds > entity->seconds_per_frame)
		{
			sl_get_instance(tile, tile->frame_index)->enabled = false;
			tile->frame_index = (tile->frame_index + 1) % tile->tile_kind->frame_count;
			sl_get_instance(tile, tile->frame_index)->enabled = true;
			entity->last_frame_seconds = data->seconds;
		}
	}
}

STATIC void	try_move_player(t_data *data)
{
	const int32_t	pixels_per_tile = (int32_t)data->texture.pixels_per_tile;
	t_player		*player;

	// TODO: Throttle speed when button is held, but allow spamming manually.
	while (sl_iterate_player_count(data) != FINISHED)
	{
		player = &data->players[data->t.player_index];
		if (mlx_is_key_down(data->mlx, player->controls.up_key))
			sl_shift_tile_pos(&player->entity->tile, 0, -pixels_per_tile, data);
		if (mlx_is_key_down(data->mlx, player->controls.down_key))
			sl_shift_tile_pos(&player->entity->tile, 0, pixels_per_tile, data);
		if (mlx_is_key_down(data->mlx, player->controls.left_key))
			sl_shift_tile_pos(&player->entity->tile, -pixels_per_tile, 0, data);
		if (mlx_is_key_down(data->mlx, player->controls.right_key))
			sl_shift_tile_pos(&player->entity->tile, pixels_per_tile, 0, data);
	}
}

STATIC void	loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	try_move_player(data);
	update_frames(data);
}

STATIC t_status	run(int argc, char **argv, t_data *data)
{
	if (sl_parse_argv(argc, argv, data) != OK)
		return (sl_any_error());
	data->mlx = mlx_init((int32_t)data->window.window_width,
			(int32_t)data->window.window_height, WINDOW_TITLE, true);
	if (data->mlx == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	if (sl_load_texture(data) != OK)
		return (sl_any_error());
	if (sl_instantiate_tile_kinds(data) != OK)
		return (sl_any_error());
	if (sl_instantiate_tile_grid(data) != OK)
		return (sl_any_error());
	if (sl_instantiate_entities(data) != OK)
		return (sl_any_error());
	if (sl_instantiate_players(data) != OK)
		return (sl_any_error());
	if (mlx_loop_hook(data->mlx, &loop, data) != true)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

int32_t	main(int argc, char **argv)
{
	static t_data	data;

	atexit(check_leaks); // TODO: Remove!
	if (run(argc, argv, &data) != OK)
	{
		sl_cleanup(&data);
		sl_print_all_errors();
		return (EXIT_FAILURE);
	}
	mlx_loop(data.mlx);
	sl_cleanup(&data);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
