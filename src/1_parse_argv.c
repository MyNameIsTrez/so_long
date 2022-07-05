/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 16:15:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	calculate_width_and_height(t_data *data)
{
	data->window.window_width = (uint32_t)data->t.char_grid.width * data->texture.pixels_per_tile;
	data->window.window_height = (uint32_t)data->t.char_grid.height * data->texture.pixels_per_tile;
}

STATIC t_status	calculate_pixels_per_tile(int scale, t_data *data)
{
	static const uint32_t	valid_pixels_per_tile[] = {
	[1] = 1,
	[2] = 5,
	[3] = 10,
	[4] = 20,
	};

	if (scale < 1 || scale > 4)
		return (ft_set_error(ERROR_INVALID_SCALE));
	data->texture.scale = valid_pixels_per_tile[scale];
	data->texture.pixels_per_tile = data->texture.scale * PIXELS_PER_TILE_UNSCALED;
	return (OK);
}

STATIC int	get_scale(int argc, char **argv)
{
	int	scale;

	// TODO: Add min and max scale checks?
	// TODO: Check if ft_atoi_safe is robust enough
	if (argc == 3 && ft_atoi_safe(argv[2], &scale) != OK)
		scale = DEFAULT_SCALE;
	else
		scale = DEFAULT_SCALE;
	return (scale);
}

STATIC bool	grid_has_invalid_character(t_data *data)
{
	if (!ft_chr_in_str(sl_get_grid_character(data), MAP_CHARACTERS))
		return (ft_set_error(ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

STATIC t_status	verify_argc(int argc)
{
	if (argc <= 1)
		return (ft_set_error(ERROR_TOO_FEW_ARGS));
	if (argc >= 4)
		return (ft_set_error(ERROR_TOO_MANY_ARGS));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(int argc, char **argv, t_data *data)
{
	char	*map_filename;

	if (verify_argc(argc) != OK)
		return (ft_get_error());
	map_filename = argv[1];
	if (ft_read_grid_from_file(&data->t.char_grid, map_filename) != OK)
		return (ft_get_error());
	sl_iterate_char_grid(data, true);
	while (sl_iterate_char_grid(data, false) != FINISHED)
		if (grid_has_invalid_character(data))
			return (ft_get_error());
	if (calculate_pixels_per_tile(get_scale(argc, argv), data) != OK)
		return (ft_get_error());
	calculate_width_and_height(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
