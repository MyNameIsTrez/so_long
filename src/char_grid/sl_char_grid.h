/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_char_grid.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:26:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:43:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_CHAR_GRID_H
# define SL_CHAR_GRID_H

////////////////////////////////////////////////////////////////////////////////

t_u8		sl_get_char_grid_character(t_data *data);
t_status	sl_init_char_grid(char *map_filename, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////