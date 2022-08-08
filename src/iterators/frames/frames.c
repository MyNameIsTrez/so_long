/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:44:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:11:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames(t_iterator *it, t_tile_kind *tile_kind,
						t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(tile_kind->frames);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.frame = *(mlx_image_t **)it->current;
		return (LOOPED);
	}
	data->it.frame = *(mlx_image_t **)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
