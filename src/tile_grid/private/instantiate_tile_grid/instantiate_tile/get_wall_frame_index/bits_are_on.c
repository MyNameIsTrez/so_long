/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bits_are_on.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 14:09:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 14:09:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	bits_are_on(size_t x, size_t y)
{
	return ((x & y) == y);
}

////////////////////////////////////////////////////////////////////////////////
