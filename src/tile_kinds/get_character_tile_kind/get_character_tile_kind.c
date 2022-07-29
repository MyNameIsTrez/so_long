/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_character_tile_kind.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 17:32:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_character_tile_kind(t_data *data)
{
	return (sl_get_tile_kind(sl_get_char_grid_character(data), data));
}

////////////////////////////////////////////////////////////////////////////////
