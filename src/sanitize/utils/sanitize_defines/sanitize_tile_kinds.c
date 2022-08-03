/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_tile_kinds.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:47:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_tile_kinds/sl_sanitize_tile_kinds.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_tile_kinds(t_data *data)
{
	if (sanitize_collectible(data) != OK || \
		sanitize_empty_space(data) != OK || \
		sanitize_map_exit(data) != OK || \
		sanitize_player(data) != OK || \
		sanitize_wall(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
