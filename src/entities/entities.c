/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:13:57 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:14:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_is_entity(t_data *data)
{
	return (ft_chr_in_str(sl_get_char_grid_character(data), ENTITY_CHARACTERS));
}

////////////////////////////////////////////////////////////////////////////////