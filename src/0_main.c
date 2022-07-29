/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 13:55:19 by sbos          ########   odam.nl         */
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

////////////////////////////////////////////////////////////////////////////////

t_i32	main(t_i32 argc, char **argv)
{
	t_data	data;

	atexit(check_leaks); // TODO: Remove!
	if (sl_init(argc, argv, loop, &data) != OK)
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
