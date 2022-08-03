/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 15:38:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "load_texture_utils/sl_load_texture_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (sl_init_texture_filename(data) != OK)
		return (sl_any_error());
	if (ft_str_assign(&tex_filepath, get_texture_filepath(data)) != OK)
		return (ft_any_error());
	data->texture.data = mlx_load_png(tex_filepath);
	if (data->texture.data == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
