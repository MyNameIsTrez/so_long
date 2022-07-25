/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_kinds_utils.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:55:20 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 15:47:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_KINDS_UTILS_H
# define SL_TILE_KINDS_UTILS_H

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_tile_kind(t_u8 character, t_data *data);
t_tile_kind	*sl_get_character_tile_kind(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////