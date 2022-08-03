/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_texture_filename.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 15:09:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "init_texture_filename_utils/sl_init_texture_filename_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_texture_filename(t_data *data)
{
	t_texture	*texture;
	char		*filename_stem;

	texture = &data->texture;
	if (get_texture_filename_stem(&filename_stem, texture) != OK)
		return (ERROR);
	texture->filename = ft_strjoin(filename_stem, TEXTURE_FILENAME_EXTENSION);
	if (texture->filename == NULL)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
