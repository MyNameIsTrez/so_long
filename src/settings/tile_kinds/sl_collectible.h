/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_collectible.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 17:57:04 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 12:59:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_COLLECTIBLE_H
# define SL_COLLECTIBLE_H

////////////////////////////////////////////////////////////////////////////////

# define COLLECTIBLE_TEXTURE_FRAME_COUNT 4
# define COLLECTIBLE_TEXTURE_ROW 46
# define COLLECTIBLE_CHARACTER 'C'
# define COLLECTIBLE_DEPTH 2
# define COLLECTIBLE_IS_ENTITY 1
# define COLLECTIBLE_TICKS_BETWEEN_FRAME_CHANGES 25
# define COLLECTIBLE_TICKS_BETWEEN_UPDATES 30

////////////////////////////////////////////////////////////////////////////////

# define COLLECTIBLE_R_WAIT 3
# define COLLECTIBLE_G_WAIT 3
# define COLLECTIBLE_B_WAIT 3

# define COLLECTIBLE_R_STEP 1
# define COLLECTIBLE_G_STEP 1
# define COLLECTIBLE_B_STEP 1

////////////////////////////////////////////////////////////////////////////////
// Light theme

// # define COLLECTIBLE_MIN_R 0
// # define COLLECTIBLE_MIN_G 0
// # define COLLECTIBLE_MIN_B 0

// # define COLLECTIBLE_R 159
// # define COLLECTIBLE_G 184
// # define COLLECTIBLE_B 173

// # define COLLECTIBLE_MAX_R 0
// # define COLLECTIBLE_MAX_G 0
// # define COLLECTIBLE_MAX_B 0

////////////////////////////////////////////////////////////////////////////////
// Dark theme

# define COLLECTIBLE_MIN_R 226
# define COLLECTIBLE_MIN_G 164
# define COLLECTIBLE_MIN_B 35

# define COLLECTIBLE_R 236
# define COLLECTIBLE_G 174
# define COLLECTIBLE_B 45

# define COLLECTIBLE_MAX_R 246
# define COLLECTIBLE_MAX_G 184
# define COLLECTIBLE_MAX_B 55

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
