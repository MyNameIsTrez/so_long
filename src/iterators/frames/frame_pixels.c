/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_pixels.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:49:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 17:38:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_pixels(mlx_image_t *frame,
								t_data *data, bool reset)
{
	if (reset)
	{
		sl_reset_iterate_frame_width(data);
		sl_reset_iterate_frame_height(data);
		return (RESET);
	}
	while (true)
	{
		while (true)
		{
			if (sl_iterate_frame_width(frame, data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_frame_width(data);
		if (data->it.frame_pixels.y == 0)
			sl_iterate_frame_height(frame, data);
		if (sl_iterate_frame_height(frame, data) != LOOPED)
			break ;
	}
	sl_reset_iterate_frame_pixels(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_pixels(mlx_image_t *frame, t_data *data)
{
	return (resettable_iterate_frame_pixels(frame, data, false));
}

void	sl_reset_iterate_frame_pixels(t_data *data)
{
	resettable_iterate_frame_pixels(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
