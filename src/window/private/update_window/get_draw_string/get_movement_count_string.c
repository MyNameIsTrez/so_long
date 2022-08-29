/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_movement_count_string.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 11:18:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/29 11:18:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

char	*get_movement_count_string(t_data *data)
{
	char	*string;
	char	*string_full;

	string = ft_itoa((t_i32)data->movement_count);
	if (string == NULL)
		return (NULL);
	string_full = ft_strjoin("Movement count: ", string);
	ft_free(&string);
	return (string_full);
}

////////////////////////////////////////////////////////////////////////////////
