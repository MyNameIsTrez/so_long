/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/22 12:44:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

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

	if (parse_argv(argc, argv, &data.grid) != SUCCESS)
		return (EXIT_FAILURE);
	data.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.images = malloc(1 * sizeof(mlx_image_t));
	data.images[0] = mlx_new_image(data.mlx, 128, 128);
	ft_memset(data.images[0]->pixels, 255, data.images[0]->width * data.images[0]->height * sizeof(uint8_t) * 4);
	mlx_image_to_window(data.mlx, data.images[0], 0, 0);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
