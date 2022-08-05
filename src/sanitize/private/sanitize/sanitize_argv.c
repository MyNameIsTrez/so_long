/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_argv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 15:22:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 22:17:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_argv(t_i32 argc, char **argv)
{
	char	*scale_string;
	t_i32	scale;

	if (argc >= 3)
	{
		scale_string = argv[2];
		// TODO: Check if ft_atoi_safe is robust enough
		if (ft_atoi_safe(scale_string, &scale) != OK || \
			(scale < 1 || scale > 4))
			return (sl_set_error(SL_ERROR_INVALID_SCALE));
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
