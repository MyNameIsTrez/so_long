/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:16:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 14:20:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_utils/sl_sanitize_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_sanitize(t_data *data)
{
	if (sanitize_tile_kinds(data) != OK)
		return (sl_any_error());
	// t_i32	min;
	// t_i32	max;

	// min = tk_data_color.initial_color[data->it.rgb_channel_index] - tk_data_color.min_color[data->it.rgb_channel_index];
	// if (min < 0)
	// 	return (SL_ERROR_TOO_LOW_MIN_COLOR);
	// max = tk_data_color.initial_color[data->it.rgb_channel_index] + tk_data_color.max_color[data->it.rgb_channel_index];
	// if (max > 255)
	// 	return (SL_ERROR_TOO_HIGH_MAX_COLOR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
