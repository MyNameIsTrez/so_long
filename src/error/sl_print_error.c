/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_print_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 13:20:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 14:41:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_print_error(void)
{
	char*const	sl_error_messages[] = {
	[SL_ERROR_FILE_HAS_INVALID_CHAR] = \
		"The input map has an invalid character.",
	[SL_ERROR_INVALID_SCALE] = \
		"The scale argument that was provided to the program is invalid.",
	[SL_ERROR_MLX42] = \
		"MLX42 reported something went wrong.",
	[SL_ERROR_TOO_MANY_PLAYERS] = \
		"There are too many player characters in the input map.",
	[SL_ERROR_TOO_LOW_MIN_COLOR] = \
		"A #defined color channel min offset was too low,"
		" causing a color channel to have a value lower than the minimum of 0.",
	[SL_ERROR_TOO_HIGH_MAX_COLOR] = \
		"A #defined color channel max offset was too high,"
		" causing a color channel to have a value higher than the maximum"
		" of 255.",
	};

	ft_print("Error: ");
	ft_putendl(sl_error_messages[sl_get_error()]);
}

////////////////////////////////////////////////////////////////////////////////
