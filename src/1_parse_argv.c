/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/23 18:32:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	free_all_images(t_data *data)
{
	int	tile_index;

	tile_index = 0;
	while (tile_index < TILE_ENUM_COUNT)
	{
		if (data->tile_images[tile_index] == NULL)
			mlx_delete_image(data->mlx, data->tile_images[tile_index]);
		tile_index++;
	}
}

STATIC t_success	check_image_errors(t_data *data)
{
	int	tile_index;

	tile_index = 0;
	while (tile_index < TILE_ENUM_COUNT)
	{
		if (data->tile_images[tile_index] == NULL)
		{
			free_all_images(data);
			return (ft_set_error(ERROR_MALLOC));
		}
		tile_index++;
	}
	return (SUCCESS);
}

STATIC t_success	get_static_tex(mlx_texture_t *tex, char *parent_path,
									char *filename)
{
	char			*filepath;

	if (ft_str_assign(ft_strjoin(parent_path, filename), &filepath) != SUCCESS)
		return (ft_set_error(ERROR_MALLOC));
	tex = mlx_load_png(filepath);
	free(filepath);
	if (tex == NULL)
		return (ft_set_error(ERROR_MLX42));
	return (SUCCESS);
}

STATIC t_success	load_animated_images(char *filename, int pix_per_tile,
										t_data *data)
{
	mlx_texture_t	*tex;
	const uint32_t	wh[2] = {pix_per_tile, pix_per_tile};

	if (get_static_tex(&tex, ANIMATED_TEXTURE_DIR_PATH, filename) != SUCCESS)
		return (ft_get_error());
	data->tile_images[EMPTY_SPACE] = mlx_texture_area_to_image(data->mlx, tex,
			(u_int32_t[]){PLAYER_TEXTURE_COLUMN, PLAYER_TEXTURE_ROW}, wh);
	// TODO: Load the two textures of an animated texture instead of just one.
	mlx_delete_texture(tex);
}

STATIC t_success	load_static_images(char *filename, int pix_per_tile,
										t_data *data)
{
	mlx_texture_t	*tex;
	const uint32_t	wh[2] = {pix_per_tile, pix_per_tile};

	if (get_static_tex(&tex, STATIC_TEXTURE_DIR_PATH, filename) != SUCCESS)
		return (ft_get_error());
	data->tile_images[EMPTY_SPACE] = mlx_texture_area_to_image(data->mlx, tex,
			(u_int32_t[]){EMPTY_SPACE_TEXTURE_COLUMN, EMPTY_SPACE_TEXTURE_ROW},
			wh);
	data->tile_images[WALL] = mlx_texture_area_to_image(data->mlx, tex,
			(u_int32_t[]){WALL_TEXTURE_COLUMN, WALL_TEXTURE_ROW}, wh);
	data->tile_images[COLLECTIBLE] = mlx_texture_area_to_image(data->mlx, tex,
			(u_int32_t[]){COLLECTIBLE_TEXTURE_COLUMN, COLLECTIBLE_TEXTURE_ROW},
			wh);
	data->tile_images[MAP_EXIT] = mlx_texture_area_to_image(data->mlx, tex,
			(u_int32_t[]){MAP_EXIT_TEXTURE_COLUMN, MAP_EXIT_TEXTURE_ROW}, wh);
	mlx_delete_texture(tex);
}

STATIC t_success	load_tile_sprites(char *filename, int pix_per_tile,
										t_data *data)
{
	load_static_images(filename, pix_per_tile, data);
	load_animated_images(filename, pix_per_tile, data);
	return (check_image_errors(data));
}

STATIC t_success	get_texture_filename(int pixels_per_tile, char **filename)
{
	const char	*str_pixels_per_tile = ft_itoa(pixels_per_tile);

	if (str_pixels_per_tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	*filename = ft_strjoin(str_pixels_per_tile, TEXTURE_FILENAME_SUFFIX);
	free(str_pixels_per_tile);
	if (*filename == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

STATIC int	get_pixels_per_tile(int scale)
{
	static const int	valid_pixels_per_tile[] = {
	[1] = 8,
	[2] = 40,
	[3] = 80,
	[4] = 160,
	};

	if (scale < 1 || scale > 4)
		return (ft_set_error(ERROR_INVALID_SCALE));
	return (valid_pixels_per_tile[scale]);
}

STATIC int	get_scale(int argc, char **argv, t_data *data)
{
	int	scale;

	// TODO: Add min and max scale checks?
	// TODO: Check if ft_atoi_safe is robust enough
	if (argc == 3 && ft_atoi_safe(argv[2], &scale) != SUCCESS)
		scale = DEFAULT_SCALE;
	else
		scale = DEFAULT_SCALE;
	return (scale);
}

STATIC bool	grid_has_invalid_character(t_grid *grid)
{
	size_t	y;
	size_t	x;
	char	chr;

	y = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			chr = grid->cells[y][x];
			if (!ft_chr_in_str(chr, MAP_CHARACTERS))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

STATIC t_success	verify_argc(int argc)
{
	if (argc <= 1)
		return (ft_set_error(ERROR_TOO_FEW_ARGS));
	if (argc >= 4)
		return (ft_set_error(ERROR_TOO_MANY_ARGS));
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data)
{
	char	*map_filename;
	char	*filename;
	int		pixels_per_tile;

	if (verify_argc(argc) != SUCCESS)
		return (ft_get_error());
	map_filename = argv[1];
	if (ft_read_grid_from_file(&data->grid, map_filename) != SUCCESS)
		return (ft_get_error());
	if (grid_has_invalid_character(&data->grid))
		return (ft_set_error(ERROR_FILE_HAS_INVALID_CHAR));
	pixels_per_tile = get_pixels_per_tile(get_scale(argc, argv, data));
	if (get_texture_filename(pixels_per_tile, &filename) != SUCCESS)
		return (ft_get_error());
	if (load_tile_sprites(filename, pixels_per_tile, data) != SUCCESS)
	{
		free(filename);
		return (ft_get_error());
	}
	free(filename);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
