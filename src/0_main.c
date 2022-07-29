/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 13:44:49 by sbos          ########   odam.nl         */
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

STATIC void	loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	// ft_printf("%d\n", data->seconds);
	// ft_printf("%d\n", data->frame);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// sl_update_frame_colors(data);
	sl_try_move_players(data);
	sl_update_held_keys(data);
	sl_change_frames(data);
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
		sl_initialize_players,
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

STATIC t_status	init(t_i32 argc, char **argv, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	sl_init_monitor_size(data);
	if (sl_parse_argv(argc, argv, data) != OK)
		return (sl_any_error());
	data->mlx = mlx_init((t_i32)data->window.width, (t_i32)data->window.height,
			WINDOW_TITLE, false);
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
		sl_cleanup(&data);
		sl_print_all_errors();
		return (EXIT_FAILURE);
	}
	// exit(EXIT_FAILURE);
	mlx_loop(data.mlx);
	sl_cleanup(&data);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
