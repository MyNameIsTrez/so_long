/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_get_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/23 13:54:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_sl_error	sl_get_error(void)
{
	return (*sl_get_error_ptr());
}

////////////////////////////////////////////////////////////////////////////////
