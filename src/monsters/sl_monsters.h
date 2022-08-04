/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_monsters.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:20:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 16:10:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_MONSTERS_H
# define SL_MONSTERS_H

////////////////////////////////////////////////////////////////////////////////

# include "sl_struct_monster.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_monsters(t_data *data);
void		sl_update_monsters(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
