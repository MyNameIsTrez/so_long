/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 16:56:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/load_texture/sl_private_load_texture.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (sl_init_texture_filename(data) != OK)
		return (ERROR);
	if (ft_str_assign(&tex_filepath, get_texture_filepath(data)) != OK)
		return (ERROR);
	data->texture.data = mlx_load_png(tex_filepath);
	if (data->texture.data == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
