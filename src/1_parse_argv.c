/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/24 16:06:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	calculate_width_and_height(t_data *data)
{
	data->width = (uint32_t)data->grid.width * data->pixels_per_tile;
	data->height = (uint32_t)data->grid.height * data->pixels_per_tile;
}

STATIC t_success	calculate_pixels_per_tile(int scale, t_data *data)
{
	static const uint32_t	valid_pixels_per_tile[] = {
	[1] = 1,
	[2] = 5,
	[3] = 10,
	[4] = 20,
	};

	if (scale < 1 || scale > 4)
		return (ft_set_error(ERROR_INVALID_SCALE));
	data->pixels_per_tile = valid_pixels_per_tile[scale];
	return (SUCCESS);
}

STATIC int	get_scale(int argc, char **argv)
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
			if (!ft_chr_in_str(chr, MAP_IMAGE_CHARACTERS))
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

	if (verify_argc(argc) != SUCCESS)
		return (ft_get_error());
	map_filename = argv[1];
	if (ft_read_grid_from_file(&data->grid, map_filename) != SUCCESS)
		return (ft_get_error());
	if (grid_has_invalid_character(&data->grid))
		return (ft_set_error(ERROR_FILE_HAS_INVALID_CHAR));
	if (calculate_pixels_per_tile(get_scale(argc, argv), data) != SUCCESS)
		return (ft_get_error());
	calculate_width_and_height(data);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
