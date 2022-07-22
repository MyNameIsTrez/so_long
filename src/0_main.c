/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:52:37 by sbos          ########   odam.nl         */
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
	t_f64		seconds_elapsed;
	t_i32		frame_count;

	while (sl_iterate_entities(data) != FINISHED)
	{
		entity = data->it.entity;
		seconds_elapsed = data->seconds - entity->last_frame_seconds;
		if (seconds_elapsed > entity->seconds_per_frame)
		{
			tile = &entity->tile;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = false;
			frame_count = tile->tile_kind->frame_count;
			tile->frame_index = (tile->frame_index + 1) % frame_count;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = true;
			entity->last_frame_seconds = data->seconds;
		}
		// TODO: Do something with varying frame rates during gameplay
		// entity->seconds_per_frame -= 0.001;
	}
}

STATIC void	loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	// ft_printf("%d\n", data->seconds);
	// ft_printf("%d\n", data->frame);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// sl_update_frames(data);
	sl_try_move_players(data);
	sl_update_held_keys(data);
	update_frames(data);
	data->frame++;
}

STATIC t_status	subinits(t_data *data)
{
	static const t_subinit	subinit_table[] = {
		sl_instantiate_background,
		sl_load_texture,
		sl_instantiate_tile_kinds,
		sl_initialize_tile_kinds_colors,
		sl_instantiate_tile_grid,
		sl_instantiate_entities,
		sl_instantiate_players
	};
	size_t					index;

	index = 0;
	while (index < sizeof(subinit_table) / sizeof(subinit_table[0]))
	{
		if (subinit_table[index](data) != OK)
			return (ERROR);
		index++;
	}
	return (OK);
}

STATIC void	init_monitor_size(t_data *data)
{
	t_i32	*width;
	t_i32	*height;

	width = &data->monitor.width;
	height = &data->monitor.height;
	mlx_get_monitor_size(0, width, height);
	if (*width <= 0)
		*width = MAX_MONITOR_WIDTH;
	if (*height <= 0)
		*height = MAX_MONITOR_HEIGHT;
}

STATIC t_status	init(t_i32 argc, char **argv, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_monitor_size(data);
	if (sl_parse_argv(argc, argv, data) != OK)
		return (sl_any_error());
	data->mlx = mlx_init(data->window.width, data->window.height, WINDOW_TITLE,
			false);
	if (data->mlx == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	if (subinits(data) != OK)
		return (sl_any_error());
	if (mlx_loop_hook(data->mlx, &loop, data) != true)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_i32	main(t_i32 argc, char **argv)
{
	t_data	data;

	atexit(check_leaks); // TODO: Remove!
	if (init(argc, argv, &data) != OK)
	{
		sl_mlx_cleanup(&data);
		ft_free_allocations();
		sl_print_all_errors();
		return (EXIT_FAILURE);
	}
	// exit(EXIT_FAILURE);
	mlx_loop(data.mlx);
	sl_mlx_cleanup(&data);
	ft_free_allocations();
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
