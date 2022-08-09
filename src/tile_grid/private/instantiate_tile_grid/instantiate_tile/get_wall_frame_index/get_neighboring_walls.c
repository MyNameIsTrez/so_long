/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_neighboring_walls.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 13:45:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 14:16:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "get_neighboring_walls/sl_private_get_neighboring_walls.h"

////////////////////////////////////////////////////////////////////////////////

size_t	get_neighboring_walls(t_tile *tile, t_data *data)
{
	size_t	neighboring_walls;

	neighboring_walls = 0;
	if (neighboring_wall(-1, 0, tile, data))
		neighboring_walls |= 1 << 0;
	if (neighboring_wall(-1, -1, tile, data))
		neighboring_walls |= 1 << 1;
	if (neighboring_wall(0, -1, tile, data))
		neighboring_walls |= 1 << 2;
	if (neighboring_wall(1, -1, tile, data))
		neighboring_walls |= 1 << 3;
	if (neighboring_wall(1, 0, tile, data))
		neighboring_walls |= 1 << 4;
	if (neighboring_wall(1, 1, tile, data))
		neighboring_walls |= 1 << 5;
	if (neighboring_wall(0, 1, tile, data))
		neighboring_walls |= 1 << 6;
	if (neighboring_wall(-1, 1, tile, data))
		neighboring_walls |= 1 << 7;
	return (neighboring_walls);
}

////////////////////////////////////////////////////////////////////////////////
