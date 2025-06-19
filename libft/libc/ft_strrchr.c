/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:07:48 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:53:54 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	last;

	if (!s)
		return (NULL);
	last = ft_strlen(s);
	while (last > 0)
	{
		if (s[last] == (char)c)
			break ;
		last--;
	}
	if (s[last] == (char)c)
		return ((char *)&s[last]);
	return (NULL);
}
