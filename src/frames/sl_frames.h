/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_frames.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:51:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_FRAMES_H
# define SL_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

void			sl_change_frames(t_data *data);
mlx_image_t		*sl_get_frame(t_tile_kind *tile_kind, size_t frame_index);
mlx_instance_t	*sl_get_frame_instance(t_tile *tile, size_t frame_index);
size_t			sl_get_pixel_index(mlx_image_t *frame, t_data *data);
t_status		sl_initialize_tile_kinds_colors(t_data *data);
bool			sl_is_opaque(t_data *data);
void			sl_update_frame_colors(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
