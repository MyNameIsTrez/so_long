/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_kinds.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:49:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:02:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_KINDS_H
# define SL_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

// TODO: Move to own header
typedef struct s_tile_kind_data_color
{
	t_u8	initial_color[3];
	t_u8	min_color[3];
	t_u8	max_color[3];
	t_u32	wait[3];
	t_i32	step[3];
}	t_tile_kind_data_color;

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_entity_tile_kind(t_data *data);
t_tile_kind	*sl_get_tile_grid_tile_kind(t_data *data);
t_status	sl_instantiate_tile_kinds(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
