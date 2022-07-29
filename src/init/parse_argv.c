/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 14:45:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

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
	if (sl_init_grid(map_filename, data) != OK)
		return (sl_any_error());
	scale_string = argv[2];
	if (sl_init_texture(argc, scale_string, data) != OK)
		return (sl_any_error());
	sl_calculate_window_width_and_height(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
