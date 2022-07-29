/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_texture_filename.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 15:09:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 15:12:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	get_str_pixels_per_tile(char **str_pixels_per_tile, t_i32 scale)
{
	*str_pixels_per_tile = ft_itoa(scale);
	if (*str_pixels_per_tile == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

STATIC t_status	get_texture_filename_stem(char **filename_stem,
					t_texture *texture)
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

t_status	sl_init_texture_filename(t_data *data)
{
	t_texture	*texture;
	char		*filename_stem;

	texture = &data->texture;
	if (get_texture_filename_stem(&filename_stem, texture) != OK)
		return (sl_any_error());
	texture->filename = ft_strjoin(filename_stem, TEXTURE_FILENAME_EXTENSION);
	if (texture->filename == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
