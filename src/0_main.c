/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 11:00:34 by sbos          ########   odam.nl         */
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

STATIC void	loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	// ft_printf("%d\n", (int)data->seconds);
	// ft_printf("%d\n", data->frame);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	sl_update_colors(data);
	sl_try_move_players(data);
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
