/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 19:36:48 by sbos          ########   odam.nl         */
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
	system("leaks -q so_long");
}

////////////////////////////////////////////////////////////////////////////////

STATIC void	loop(void *param)
{
	const t_data	*data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	// 	data->images[0]->instances[0].y -= 5;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	// 	data->images[0]->instances[0].y += 5;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	// 	data->images[0]->instances[0].x -= 5;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	// 	data->images[0]->instances[0].x += 5;
}

////////////////////////////////////////////////////////////////////////////////

int32_t	main(int argc, char **argv)
{
	static t_data	data;

	atexit(check_leaks);
	if (sl_parse_argv(argc, argv, &data) != SUCCESS)
		return (EXIT_FAILURE);
	data.mlx = mlx_init((int32_t)data.window_width, (int32_t)data.window_height, "so_long",
			true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	if (sl_load_texture(&data) != SUCCESS)
		return (EXIT_FAILURE);
	if (sl_instantiate_tile_types(&data) != SUCCESS)
		return (EXIT_FAILURE);
	if (sl_instantiate_tile_grid(&data) != SUCCESS)
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
