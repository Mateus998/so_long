/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:19:23 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:46:32 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	while (i < n && cs1[i] == cs2[i])
		i++;
	if (i == n)
		return (0);
	return (cs1[i] - cs2[i]);
}
