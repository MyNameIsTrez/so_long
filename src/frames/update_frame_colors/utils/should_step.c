/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   should_step.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:48:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:56:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_should_step(t_data *data)
{
	t_i32	*wait;
	size_t	rgb_channel_index;

	wait = data->it.tile_kind->color.wait;
	rgb_channel_index = data->it.rgb_channel_index;
	return (data->frame % wait[rgb_channel_index] == 0);
}

////////////////////////////////////////////////////////////////////////////////
