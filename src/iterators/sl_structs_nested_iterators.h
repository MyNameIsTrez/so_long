/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_nested_iterators.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:21:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 13:42:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_NESTED_ITERATORS_H
# define SL_STRUCTS_NESTED_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

// typedef struct s_it_frames_pixel_indices
// {
// 	t_iterator	frame_pixel_indices_it;
// 	t_iterator	frames_it;
// }	t_it_frames_pixel_indices;

typedef struct s_it_frame_rgb_channel_indices
{
	t_iterator	rgb_channel_indices_it;
	t_iterator	frame_pixel_indices_it;
}	t_it_frame_rgb_channel_indices;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
