/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "utils/sl_init_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(t_i32 argc, char **argv, t_data *data)
{
	char	*map_filename;

	map_filename = argv[1];
	if (sl_init_char_grid(map_filename, data) != OK)
		return (ERROR);
	if (sl_init_texture_metadata(get_scale(argc, argv), data) != OK)
		return (ERROR);
	sl_init_window_width_and_height(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
