/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_texture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC char	*get_texture_scales_path(void)
{
	return (TEXTUREPACKS_PATH TEXTUREPACK TEXTURE_SCALES_DIR);
}

STATIC char	*get_texture_filepath(t_data *data)
{
	return (ft_strjoin(get_texture_scales_path(), data->texture.filename));
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (sl_init_texture_filename(data) != OK)
		return (sl_any_error());
	if (ft_str_assign(&tex_filepath, get_texture_filepath(data)) != OK)
		return (ft_set_error(FT_ERROR_MALLOC));
	data->texture.data = mlx_load_png(tex_filepath);
	if (data->texture.data == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
