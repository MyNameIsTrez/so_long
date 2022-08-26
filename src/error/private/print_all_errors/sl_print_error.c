/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_print_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 13:20:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:32:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_error.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_print_error(void)
{
	char*const	sl_error_messages[] = {
	[SL_ERROR_MAP_NOT_ENCLOSED] = "The map is not enclosed by walls.",
	[SL_ERROR_FILE_HAS_INVALID_CHAR] = \
		"The map has an invalid character.",
	[SL_ERROR_FILE_HAS_DUPLICATE_CHAR] = \
		"The map has a duplicate character.",
	[SL_ERROR_INVALID_SCALE] = \
		"The scale argument that was provided to the program was invalid.",
	[SL_ERROR_MLX42] = \
		"MLX42 reported something went wrong.",
	[SL_ERROR_TOO_HIGH_MIN_COLOR] = \
		"A #defined minimum color channel was too high.",
	[SL_ERROR_TOO_LOW_MAX_COLOR] = \
		"A #defined maximum color channel was too low.",
	[SL_ERROR_NO_PATH] = "No path from the player to an exit was found."
	};

	ft_print("Error: ");
	ft_putendl(sl_error_messages[sl_get_error()]);
}

////////////////////////////////////////////////////////////////////////////////
