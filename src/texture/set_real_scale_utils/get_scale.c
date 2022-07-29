/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_scale.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:50:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:51:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	get_scale(t_i32 argc, char *scale_string)
{
	t_i32	scale;

	// TODO: Add min and max scale checks?
	// TODO: Check if ft_atoi_safe is robust enough
	if (argc == 3)
	{
		if (ft_atoi_safe(scale_string, &scale) != OK)
			scale = DEFAULT_SCALE;
	}
	else
		scale = DEFAULT_SCALE;
	return (scale);
}

////////////////////////////////////////////////////////////////////////////////
