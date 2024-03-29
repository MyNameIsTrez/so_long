/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_get_neighboring_walls.h                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 14:14:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 14:14:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_GET_NEIGHBORING_WALLS_H
# define SL_PRIVATE_GET_NEIGHBORING_WALLS_H

////////////////////////////////////////////////////////////////////////////////

bool	neighboring_wall(t_i32 column_offset, t_i32 row_offset, t_tile *tile,
			t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
