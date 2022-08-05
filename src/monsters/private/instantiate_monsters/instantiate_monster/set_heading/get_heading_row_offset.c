/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_heading_row_offset.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 19:18:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:18:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_heading_column_offset.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 19:16:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:18:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	get_heading_row_offset(t_heading heading)
{
	if (heading == HEADING_UP)
		return (-1);
	if (heading == HEADING_DOWN)
		return (1);
	else
		return (0);
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
