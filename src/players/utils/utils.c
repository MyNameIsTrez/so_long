/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:28:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:35:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	sl_get_key_column_offset(keys_t key, t_controls *controls)
{
	if (key == controls->left_key)
		return (-1);
	if (key == controls->right_key)
		return (1);
	else
		return (0);
}

t_i32	sl_get_key_row_offset(keys_t key, t_controls *controls)
{
	if (key == controls->up_key)
		return (-1);
	if (key == controls->down_key)
		return (1);
	else
		return (0);
}

////////////////////////////////////////////////////////////////////////////////
