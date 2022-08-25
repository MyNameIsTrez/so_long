/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_heading_index.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 18:51:30 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:55:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Only call this function
 * if you've already checked the index will be in bounds!
 *
 * @param heading
 * @param tile
 * @param data
 * @return
 */
size_t	sl_get_heading_index(t_heading heading, t_tile *tile, t_data *data)
{
	size_t		heading_column;
	size_t		heading_row;

	heading_column = (size_t)sl_get_heading_column(heading, tile, data);
	heading_row = (size_t)sl_get_heading_row(heading, tile, data);
	return (sl_get_index(heading_column, heading_row, data));
}

////////////////////////////////////////////////////////////////////////////////
