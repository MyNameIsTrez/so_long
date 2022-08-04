/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_defines.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:47:55 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_sanitize_defines.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_defines(t_data *data)
{
	if (sanitize_tile_kinds(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////