/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_kinds.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:49:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:57:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_KINDS_H
# define SL_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind_data
{
	size_t				frame_count;
	size_t				texture_row;
	t_u8				character;
	t_i32				depth;
	t_tile_kind_color	color;
}	t_tile_kind_data;

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_character_tile_kind(t_data *data);
t_tile_kind	*sl_get_tile_kind(t_u8 character, t_data *data);
t_status	sl_instantiate_tile_kinds(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
