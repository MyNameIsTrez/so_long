/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_allocation_count_string.c                      :+:    :+:            */
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

char	*get_allocation_count_string(void)
{
	char	*string;
	char	*string_full;

	string = ft_itoa((t_i32)ft_get_allocation_count());
	if (string == NULL)
		return (NULL);
	string_full = ft_strjoin("Allocation count: ", string);
	ft_free(&string);
	return (string_full);
}

////////////////////////////////////////////////////////////////////////////////
