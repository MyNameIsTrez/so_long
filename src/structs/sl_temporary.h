/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_temporary.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 17:03:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TEMPORARY_H
# define SL_TEMPORARY_H

////////////////////////////////////////////////////////////////////////////////

// This struct is used for Temporary data storage. Used by iterators.
typedef struct s_t
{
	uint32_t	column_index;
	uint32_t	row_index;
	uint32_t	frame_index;
	uint32_t	player_index;
	uint32_t	tile_kind_index;
	t_entity	*entity;
	keys_t		key;
}	t_t;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
