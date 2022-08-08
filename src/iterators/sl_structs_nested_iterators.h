/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_nested_iterators.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:21:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:39:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_NESTED_ITERATORS_H
# define SL_STRUCTS_NESTED_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_it_frame_pixels
{
	t_iterator	width_it;
	t_iterator	height_it;
}	t_it_frame_pixels;

typedef struct s_it_frames_pixel_indices
{
	t_it_frame_pixels	frame_pixel_indices_it;
	t_iterator			frames_it;
}	t_it_frames_pixel_indices;

typedef struct s_it_frame_rgb_channel_indices
{
	t_iterator			rgb_channel_indices_it;
	t_it_frame_pixels	frame_pixels_it;
}	t_it_frame_rgb_channel_indices;

typedef struct s_it_char_grid
{
	t_iterator	width_it;
	t_iterator	height_it;
}	t_it_char_grid;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
