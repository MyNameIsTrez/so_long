/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_kinds.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:49:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 14:32:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_KINDS_H
# define SL_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind_data_color
{
	t_u8	initial_color[3];
	t_u8	min_color[3];
	t_u8	max_color[3];
	t_u32	wait[3];
	t_i32	step[3];
}	t_tile_kind_data_color;

typedef struct s_tile_kind_data
{
	size_t					frame_count;
	size_t					texture_row;
	t_u8					character;
	bool					is_entity;
	t_i32					depth;
	t_tile_kind_data_color	color;
}	t_tile_kind_data;

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_entity_tile_kind(t_data *data);
t_tile_kind	*sl_get_tile_grid_tile_kind(t_data *data);
t_status	sl_instantiate_tile_kinds(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
