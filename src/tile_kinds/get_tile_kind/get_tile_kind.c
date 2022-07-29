/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_tile_kind.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 17:28:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

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

////////////////////////////////////////////////////////////////////////////////
