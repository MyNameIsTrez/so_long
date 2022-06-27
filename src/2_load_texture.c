/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_load_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:54:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/27 12:59:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	get_texture_filename_stem(char *str_pixels_per_tile,
			char **filename_stem)
{
	*filename_stem = ft_strjoin(TEXTURE_FILENAME_PREFIX, str_pixels_per_tile);
	free(str_pixels_per_tile);
	if (*filename_stem == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

STATIC t_success	get_texture_filename(t_data *data)
{
	char	*str_pixels_per_tile;
	char	*filename_stem;

	str_pixels_per_tile = ft_itoa((int)data->scale);
	if (str_pixels_per_tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	if (get_texture_filename_stem(str_pixels_per_tile,
			&filename_stem) != SUCCESS)
		return (ft_get_error());
	data->texture_filename = ft_strjoin(filename_stem, TEXTURE_FILENAME_EXTENSION);
	free(filename_stem);
	if (data->texture_filename == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_load_texture(t_data *data)
{
	char			*tex_filepath;

	if (get_texture_filename(data) != SUCCESS)
		return (ft_get_error());
	if (ft_str_assign(&tex_filepath, ft_strjoin(
				TEXTUREPACKS_PATH TEXTUREPACK TEXTURE_SCALES_DIR,
				data->texture_filename)) != SUCCESS)
		return (ft_set_error(ERROR_MALLOC));
	data->texture = mlx_load_png(tex_filepath);
	free(tex_filepath);
	if (data->texture == NULL)
		return (ft_set_error(ERROR_MLX42));
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
