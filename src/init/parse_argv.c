/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 15:41:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(t_i32 argc, char **argv, t_data *data)
{
	char	*map_filename;
	char	*scale_string;

	map_filename = argv[1];
	if (sl_init_char_grid(map_filename, data) != OK)
		return (sl_any_error());
	scale_string = argv[2];
	if (sl_init_texture_metadata(argc, scale_string, data) != OK)
		return (sl_any_error());
	sl_init_window_width_and_height(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
