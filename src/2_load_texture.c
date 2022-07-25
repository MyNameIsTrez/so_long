/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_load_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 15:03:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	get_texture_filename_stem(char *str_pixels_per_tile,
					char **filename_stem)
{
	*filename_stem = ft_strjoin(TEXTURE_FILENAME_PREFIX, str_pixels_per_tile);
	if (*filename_stem == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

STATIC t_status	get_texture_filename(t_data *data)
{
	t_texture	*texture;
	char		*str_pixels_per_tile;
	char		*filename_stem;

	texture = &data->texture;
	str_pixels_per_tile = ft_itoa(texture->scale);
	if (str_pixels_per_tile == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (get_texture_filename_stem(str_pixels_per_tile, &filename_stem) != OK)
		return (sl_any_error());
	texture->filename = ft_strjoin(filename_stem, TEXTURE_FILENAME_EXTENSION);
	if (texture->filename == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (get_texture_filename(data) != OK)
		return (sl_any_error());
	if (ft_str_assign(&tex_filepath, ft_strjoin(
				TEXTUREPACKS_PATH TEXTUREPACK TEXTURE_SCALES_DIR,
				data->texture.filename)) != OK)
		return (ft_set_error(FT_ERROR_MALLOC));
	data->texture.data = mlx_load_png(tex_filepath);
	if (data->texture.data == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
