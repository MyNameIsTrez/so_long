/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_texture_metadata.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:29:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:48:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "init_texture_metadata_utils/sl_init_texture_metadata_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_texture_metadata(t_i32 argc, char *scale_string,
				t_data *data)
{
	if (sl_set_real_scale(argc, scale_string, data) != OK)
		return (sl_any_error());
	set_pixels_per_tile(data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
