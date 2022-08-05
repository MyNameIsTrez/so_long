/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_is_walkable.h                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 16:14:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 16:15:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_IS_WALKABLE_H
# define SL_PRIVATE_IS_WALKABLE_H

////////////////////////////////////////////////////////////////////////////////

t_i32	get_key_column_offset(keys_t key, keys_t movement_keys[4]);
t_i32	get_key_row_offset(keys_t key, keys_t movement_keys[4]);
bool	is_entity_walkable(size_t column, size_t row, t_data *data);
bool	is_tile_walkable(size_t column, size_t row, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
