/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_settings_map_characters.h                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 18:02:55 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 16:31:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_SETTINGS_MAP_CHARACTERS_H
# define SL_SETTINGS_MAP_CHARACTERS_H

////////////////////////////////////////////////////////////////////////////////

# ifdef BONUS
#  define MAP_CHARACTERS "01CEMPp"
#  define ENTITY_CHARACTERS "CMPp"
#  define PLAYER_CHARACTERS "Pp"
# else
#  define MAP_CHARACTERS "01CEP"
#  define ENTITY_CHARACTERS "CP"
#  define PLAYER_CHARACTERS "P"
# endif

# define WALKABLE_CHARACTERS "0CE"

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
