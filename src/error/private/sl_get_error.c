/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_get_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/23 13:54:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:50:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_private_error.h"

////////////////////////////////////////////////////////////////////////////////

t_sl_error	sl_get_error(void)
{
	return (*sl_get_error_ptr());
}

////////////////////////////////////////////////////////////////////////////////
