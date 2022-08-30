/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_argv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 15:22:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 13:45:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_argv(t_i32 argc, char **argv)
{
	size_t	len;
	char	*map_name;
	char	*scale_string;
	t_i32	scale;

	map_name = argv[1];
	len = ft_strlen(map_name);
	if (len < 4 || !ft_str_eq(map_name + len - 4, ".ber"))
		return (sl_set_error(SL_ERROR_INVALID_FILENAME));
	if (argc >= 3)
	{
		scale_string = argv[2];
		if (ft_atoi_safe(scale_string, &scale) != OK || \
			(scale < 1 || scale > 4))
			return (sl_set_error(SL_ERROR_INVALID_SCALE));
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
