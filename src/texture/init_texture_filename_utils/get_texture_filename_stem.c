/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture_filename_stem.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:46:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:55:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_init_texture_filename_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	get_texture_filename_stem(char **filename_stem, t_texture *texture)
{
	char		*str_pixels_per_tile;

	if (get_str_pixels_per_tile(&str_pixels_per_tile,
			(t_i32)texture->scale) != OK)
		return (ft_set_error(FT_ERROR_MALLOC));
	*filename_stem = ft_strjoin(TEXTURE_FILENAME_PREFIX, str_pixels_per_tile);
	if (*filename_stem == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
