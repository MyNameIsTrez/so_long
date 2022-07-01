/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_load_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 17:43:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	get_texture_filename_stem(char *str_pixels_per_tile,
			char **filename_stem)
{
	*filename_stem = ft_strjoin(TEXTURE_FILENAME_PREFIX, str_pixels_per_tile);
	free(str_pixels_per_tile);
	if (*filename_stem == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (OK);
}

STATIC t_status	get_texture_filename(t_data *data)
{
	char	*str_pixels_per_tile;
	char	*filename_stem;

	str_pixels_per_tile = ft_itoa((int)data->scale);
	if (str_pixels_per_tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	if (get_texture_filename_stem(str_pixels_per_tile,
			&filename_stem) != OK)
		return (ft_get_error());
	data->texture.filename = ft_strjoin(filename_stem, TEXTURE_FILENAME_EXTENSION);
	free(filename_stem);
	if (data->texture.filename == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (get_texture_filename(data) != OK)
		return (ft_get_error());
	if (ft_str_assign(&tex_filepath, ft_strjoin(
				TEXTUREPACKS_PATH TEXTUREPACK TEXTURE_SCALES_DIR,
				data->texture.filename)) != OK)
		return (ft_set_error(ERROR_MALLOC));
	data->texture.data = mlx_load_png(tex_filepath);
	free(tex_filepath);
	if (data->texture.data == NULL)
		return (ft_set_error(ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
