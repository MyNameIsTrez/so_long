/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   has_basic_characters.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 21:11:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 21:11:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "has_basic_characters/sl_private_has_basic_characters.h"

////////////////////////////////////////////////////////////////////////////////

t_status	has_basic_characters(t_data *data)
{
	if (missing_start(data))
		return (sl_set_error(SL_ERROR_MISSING_START));
	if (missing_collectible(data))
		return (sl_set_error(SL_ERROR_MISSING_COLLECTIBLE));
	if (missing_exit(data))
		return (sl_set_error(SL_ERROR_MISSING_EXIT));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
