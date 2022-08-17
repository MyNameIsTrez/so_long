/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_column.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 18:39:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:39:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

size_t	sl_get_column(size_t index, t_data *data)
{
	return (index % data->char_grid.width);
}

////////////////////////////////////////////////////////////////////////////////