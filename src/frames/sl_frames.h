/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_frames.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 16:23:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_FRAMES_H
# define SL_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind	t_tile_kind;
typedef struct s_tile		t_tile;

////////////////////////////////////////////////////////////////////////////////

void			sl_change_frames(t_data *data);
mlx_image_t		*sl_get_frame(t_tile_kind *tile_kind, size_t frame_index);
mlx_instance_t	*sl_get_frame_instance(t_tile *tile, size_t frame_index);
t_status		sl_initialize_tile_kinds_colors(t_data *data);
void			sl_update_frame_colors(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
