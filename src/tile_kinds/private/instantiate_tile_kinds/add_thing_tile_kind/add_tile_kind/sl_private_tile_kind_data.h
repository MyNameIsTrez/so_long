/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_tile_kind_data.h                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 17:45:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:02:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_TILE_KIND_DATA_H
# define SL_PRIVATE_TILE_KIND_DATA_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind_data
{
	size_t					frame_count;
	size_t					texture_row;
	t_u8					character;
	bool					is_entity;
	t_i32					depth;
	t_u32					ticks_between_frame_changes;
	t_u32					ticks_between_updates;
	t_tile_kind_data_color	color;
}	t_tile_kind_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
