/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_texture_metadata.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:29:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 16:56:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/init_texture_metadata/sl_private_init_texture_metadata.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_texture_metadata(t_i32 scale, t_data *data)
{
	if (sl_set_real_scale(scale, data) != OK)
		return (ERROR);
	set_pixels_per_tile(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
