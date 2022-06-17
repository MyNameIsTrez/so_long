/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 12:40:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/29 14:46:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Locates the last @p chr in @p str.
 *
 * @param str
 * @param chr
 * @return A pointer to the last @p chr in @p str;\n
   NULL if @p chr isn't in @p str.
 */
char	*ft_strrchr(const char *str, int chr)
{
	size_t	i;
	char	c;

	c = (char)chr;
	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		i--;
		if (str[i] == c)
			return ((char *)&str[i]);
	}
	return (NULL);
}

////////////////////////////////////////////////////////////////////////////////
