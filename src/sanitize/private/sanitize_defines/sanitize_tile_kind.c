/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_tile_kind.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:54:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_color_offset/sl_sanitize_color_offset.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_tile_kind(t_tile_kind_data_color tile_kind_data_color,
				t_data *data)
{
	if (sanitize_min_color_offset(tile_kind_data_color, data) != OK || \
		sanitize_max_color_offset(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
