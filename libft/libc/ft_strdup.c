/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:11 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:21:47 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	if (!s)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, ft_strlen(s) + 1);
	return (dest);
}
