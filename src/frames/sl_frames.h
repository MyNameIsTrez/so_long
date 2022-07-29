/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_frames.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:40:53 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_FRAMES_H
# define SL_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

# include "get_frame/sl_get_frame.h"
# include "get_frame_instance/sl_get_frame_instance.h"
# include "get_pixel_index/sl_get_pixel_index.h"
# include "is_opaque/sl_is_opaque.h"

////////////////////////////////////////////////////////////////////////////////

void		sl_change_frames(t_data *data);
t_status	sl_initialize_tile_kinds_colors(t_data *data);
void		sl_update_frame_colors(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
