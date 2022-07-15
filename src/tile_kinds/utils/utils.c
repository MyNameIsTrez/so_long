/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:49:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 14:30:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_tile_kind(t_u8 character, t_data *data)
{
	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		if (data->it.tile_kind->character == character)
		{
			sl_reset_iterate_tile_kinds(data);
			return (data->it.tile_kind);
		}
	}
	return (NULL);
}

t_tile_kind	*sl_get_character_tile_kind(t_data *data)
{
	return (sl_get_tile_kind(sl_get_char_grid_character(data), data));
}

////////////////////////////////////////////////////////////////////////////////
