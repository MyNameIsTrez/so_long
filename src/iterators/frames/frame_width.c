/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:52:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:35:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_width(mlx_image_t *frame,
			t_data *data, bool reset)
{
	static t_u32	x;

	if (reset)
	{
		x = 0;
		data->it.frame_pixels.x = 0;
		return (RESET);
	}
	while (x < frame->width)
	{
		data->it.frame_pixels.x = x;
		x++;
		return (LOOPED);
	}
	sl_reset_iterate_frame_width(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_width(mlx_image_t *frame, t_data *data)
{
	return (resettable_iterate_frame_width(frame, data, false));
}

void	sl_reset_iterate_frame_width(t_data *data)
{
	resettable_iterate_frame_width(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
