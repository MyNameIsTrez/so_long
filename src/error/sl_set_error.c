/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_set_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/23 13:50:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 14:59:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_set_error(t_sl_error sl_error)
{
	*sl_get_error_ptr() = sl_error;
	return (ERROR);
}

////////////////////////////////////////////////////////////////////////////////