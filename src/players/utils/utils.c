/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:28:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:22:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	get_key_column_offset(keys_t key, keys_t movement_keys[4])
{
	if (key == movement_keys[LEFT_MOVEMENT_KEY_INDEX])
		return (-1);
	if (key == movement_keys[RIGHT_MOVEMENT_KEY_INDEX])
		return (1);
	else
		return (0);
}

t_i32	get_key_row_offset(keys_t key, keys_t movement_keys[4])
{
	if (key == movement_keys[UP_MOVEMENT_KEY_INDEX])
		return (-1);
	if (key == movement_keys[DOWN_MOVEMENT_KEY_INDEX])
		return (1);
	else
		return (0);
}

////////////////////////////////////////////////////////////////////////////////
