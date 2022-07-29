/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 14:29:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_i32	get_scale(t_i32 argc, char *scale_string)
{
	t_i32	scale;

	// TODO: Add min and max scale checks?
	// TODO: Check if ft_atoi_safe is robust enough
	if (argc == 3)
	{
		if (ft_atoi_safe(scale_string, &scale) != OK)
			scale = DEFAULT_SCALE;
	}
	else
		scale = DEFAULT_SCALE;
	return (scale);
}

STATIC bool	grid_has_invalid_character(t_data *data)
{
	while (sl_iterate_char_grid(data) != FINISHED)
		if (!ft_chr_in_str(sl_get_char_grid_character(data), MAP_CHARACTERS))
			return (sl_set_error(SL_ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

STATIC t_status	verify_argc(t_i32 argc)
{
	if (argc <= 1)
		return (ft_set_error(FT_ERROR_TOO_FEW_ARGS));
	if (argc >= 4)
		return (ft_set_error(FT_ERROR_TOO_MANY_ARGS));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(t_i32 argc, char **argv, t_data *data)
{
	char	*map_filename;
	char	*scale_string;

	if (verify_argc(argc) != OK)
		return (sl_any_error());
	map_filename = argv[1];
	if (ft_read_grid_from_file(&data->char_grid, map_filename) != OK)
		return (sl_any_error());
	if (grid_has_invalid_character(data) != OK)
		return (sl_any_error());
	scale_string = argv[2];
	if (sl_set_real_scale(get_scale(argc, scale_string), data) != OK)
		return (sl_any_error());
	data->texture.pixels_per_tile = data->texture.scale * PIXELS_PER_TILE_UNSCALED;
	sl_calculate_window_width_and_height(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
