/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:29:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 14:45:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	set_pixels_per_tile(t_data *data)
{
	data->texture.pixels_per_tile = data->texture.scale * PIXELS_PER_TILE_UNSCALED;
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_texture(t_i32 argc, char *scale_string, t_data *data)
{
	if (sl_set_real_scale(argc, scale_string, data) != OK)
		return (sl_any_error());
	set_pixels_per_tile(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
