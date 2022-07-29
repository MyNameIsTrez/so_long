/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:44:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frames(t_tile_kind *tile_kind,
								t_data *data, bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.frame = NULL;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_array_iterator(tile_kind->frames, tile_kind->frame_count, sizeof(mlx_image_t *));
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.frame = *(mlx_image_t **)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_frames(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data)
{
	return (resettable_iterate_frames(tile_kind, data, false));
}

void	sl_reset_iterate_frames(t_data *data)
{
	resettable_iterate_frames(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
