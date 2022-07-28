/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_frame_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:33:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 14:05:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_FRAME_UTILS_H
# define SL_FRAME_UTILS_H

////////////////////////////////////////////////////////////////////////////////

size_t			sl_get_pixel_index(mlx_image_t *frame, t_data *data);
mlx_image_t		*sl_get_frame(t_tile_kind *tile_kind, size_t frame_index);
mlx_instance_t	*sl_get_frame_instance(t_tile *tile, size_t frame_index);
bool			sl_is_color(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
