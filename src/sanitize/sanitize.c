/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:16:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "utils/sl_sanitize_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_sanitize(t_i32 argc, char **argv, t_data *data)
{
	if (sanitize_defines(data) != OK)
		return (ERROR);
	if (sanitize_argc(argc) != OK)
		return (ERROR);
	if (sanitize_argv(argc, argv, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
