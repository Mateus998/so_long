/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:20:12 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:08:06 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	jsize;
	char	*join;

	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strlen(s1) > (size_t) - 1 - ft_strlen(s2) - 1)
			return (NULL);
		jsize = ft_strlen(s1) + ft_strlen(s2) + 1;
		join = (char *)malloc(jsize * sizeof(char));
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, s1, jsize);
		ft_strlcat(join, s2, jsize);
	}
	else
		return (ft_strdup(""));
	return (join);
}
