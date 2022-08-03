/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_instantiate_entity.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:01:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_instantiate_entities_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	try_instantiate_entity(t_data *data)
{
	if (sl_is_entity(data) && instantiate_entity(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
