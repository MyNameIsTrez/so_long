/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_frames.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 13:24:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_FRAMES_H
# define SL_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

# include "utils/sl_frame_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_tile_kinds_colors(t_data *data);
void		sl_update_frame_colors(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
