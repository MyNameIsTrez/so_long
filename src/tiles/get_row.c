/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_row.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 18:40:30 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:40:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

size_t	sl_get_row(size_t index, t_data *data)
{
	return (index / data->char_grid.width);
}

////////////////////////////////////////////////////////////////////////////////
