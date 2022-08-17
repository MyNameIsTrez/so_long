/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 16:15:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:42:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ERROR_H
# define SL_ERROR_H

////////////////////////////////////////////////////////////////////////////////

typedef enum e_sl_error
{
	SL_OK,
	SL_ERROR_FILE_HAS_INVALID_CHAR,
	SL_ERROR_FILE_HAS_DUPLICATE_CHAR,
	SL_ERROR_INVALID_SCALE,
	SL_ERROR_MLX42,
	SL_ERROR_TOO_HIGH_MIN_COLOR,
	SL_ERROR_TOO_LOW_MAX_COLOR,
	SL_ERROR_NO_PATH,
	SL_ERROR_COUNT,
}	t_sl_error;

////////////////////////////////////////////////////////////////////////////////

t_status	sl_any_error(void);
void		sl_print_all_errors(void);
t_status	sl_set_error(t_sl_error sl_error);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
