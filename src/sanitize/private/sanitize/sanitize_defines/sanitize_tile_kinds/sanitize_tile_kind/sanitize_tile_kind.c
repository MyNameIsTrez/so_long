/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_tile_kind.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:54:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 16:43:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_private_sanitize_tile_kind.h"

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
