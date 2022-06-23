/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/23 15:58:44 by sbos          ########   odam.nl         */
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->images[0]->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->images[0]->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->images[0]->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->images[0]->instances[0].x += 5;
}

////////////////////////////////////////////////////////////////////////////////

int32_t	main(int argc, char **argv)
{
	t_data	data;

	atexit(check_leaks);
	if (sl_parse_argv(argc, argv, &data) != SUCCESS)
		return (EXIT_FAILURE);
	data.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.images = malloc(1 * sizeof(mlx_image_t));
	mlx_texture_t	*tex;
	tex = mlx_load_png("textures/BitsyDungeonTiles/tiles_static_400x400.png");
	uint32_t	xy[] = {0, 0};
	uint32_t	wh[] = {8 * 10, 8 * 10};
	data.images[0] = mlx_texture_area_to_image(data.mlx, tex, xy, wh);
	mlx_image_to_window(data.mlx, data.images[0], 0, 0);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
