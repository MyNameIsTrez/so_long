/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_real_scale.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:35:10 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_i32	get_scale(t_i32 argc, char *scale_string)
{
	t_i32	scale;

	// TODO: Add min and max scale checks?
	// TODO: Check if ft_atoi_safe is robust enough
	if (argc == 3)
	{
		if (ft_atoi_safe(scale_string, &scale) != OK)
			scale = DEFAULT_SCALE;
	}
	else
		scale = DEFAULT_SCALE;
	return (scale);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_set_real_scale(t_i32 argc, char *scale_string, t_data *data)
{
	static const size_t	valid_pixels_per_tile[] = {
	[1] = 1,
	[2] = 5,
	[3] = 10,
	[4] = 20,
	};
	t_i32				scale;
	t_texture			*texture;

	scale = get_scale(argc, scale_string);
	if (scale < 1 || scale > 4)
		return (sl_set_error(SL_ERROR_INVALID_SCALE));
	texture = &data->texture;
	texture->scale = valid_pixels_per_tile[scale];
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
