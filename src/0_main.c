/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 10:35:53 by sbos          ########   odam.nl         */
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

STATIC bool	can_autowalk(uint32_t frames_held)
{
	const bool	held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
	const bool	is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;

	return (held_long_enough && is_autowalk_frame);
}

STATIC bool	should_player_shift(keys_t key, t_data *data)
{
	const bool		holding_key = mlx_is_key_down(data->mlx, key);
	const uint32_t	frames_held = data->held_keys[key];
	const bool		key_wasnt_pressed = frames_held == 0;

	return (holding_key && (key_wasnt_pressed || can_autowalk(frames_held)));
}

STATIC void	shift_player(t_player *player, int32_t x, int32_t y, t_data *data)
{
	sl_shift_tile_pos(&player->entity->tile, x, y, data);
}

STATIC void	try_move_players(t_data *data)
{
	const int32_t	pixels_per_tile = (int32_t)data->texture.pixels_per_tile;
	t_player		*player;

	while (sl_iterate_player_count(data) != FINISHED)
	{
		player = &data->players[data->t.player_index];
		if (should_player_shift(player->controls.up_key, data))
			shift_player(player, 0, -pixels_per_tile, data);
		if (should_player_shift(player->controls.down_key, data))
			shift_player(player, 0, pixels_per_tile, data);
		if (should_player_shift(player->controls.left_key, data))
			shift_player(player, -pixels_per_tile, 0, data);
		if (should_player_shift(player->controls.right_key, data))
			shift_player(player, pixels_per_tile, 0, data);
	}
}

STATIC void	loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	// ft_printf("%d\n", (int)data->seconds);
	// ft_printf("%d\n", data->frame);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	try_move_players(data);
	sl_update_held_keys(data);
	update_frames(data);
	data->frame++;
}

STATIC t_status	run(int argc, char **argv, t_data *data)
{
	if (sl_parse_argv(argc, argv, data) != OK)
		return (sl_any_error());
	data->mlx = mlx_init((int32_t)data->window.width,
			(int32_t)data->window.height, WINDOW_TITLE, true);
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
