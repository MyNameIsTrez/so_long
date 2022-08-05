/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_sanitize_defines.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 15:15:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:23:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_SANITIZE_DEFINES_H
# define SL_PRIVATE_SANITIZE_DEFINES_H

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_defines(t_data *data);
t_status	sanitize_tile_kinds(t_data *data);
t_status	sanitize_tile_kind(t_tile_kind_data_color tile_kind_data_color,
				t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
