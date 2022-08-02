/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tile_kind.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:00:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/02 15:51:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind(t_tile_kind_data tk_data, t_data *data)
{
	t_tile_kind	tile_kind;

	tile_kind.character = tk_data.character;
	tile_kind.frame_count = tk_data.frame_count;
	tile_kind.frames = ft_vector_new(sizeof(mlx_image_t *));
	if (tile_kind.frames == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	if (add_tile_kind_frames(&tile_kind, tk_data.frame_count,
			tk_data.texture_row, data) != OK)
		return (sl_any_error());
	tile_kind.depth = tk_data.depth;
	if (instantiate_tile_kind_color(&tile_kind.color, tk_data.color, data) != OK)
		return (sl_any_error());
	if (ft_vector_push(&data->tile_kinds, &tile_kind) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
