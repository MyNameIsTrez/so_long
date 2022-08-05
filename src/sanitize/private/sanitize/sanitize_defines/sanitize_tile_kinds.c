/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_tile_kinds.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:47:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:27:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_tile_kinds/sl_private_sanitize_tile_kinds.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_tile_kinds(t_data *data)
{
	if (sanitize_collectible(data) != OK || \
		sanitize_empty_space(data) != OK || \
		sanitize_map_exit(data) != OK || \
		sanitize_player_1(data) != OK || \
		sanitize_player_2(data) != OK || \
		sanitize_wall(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
