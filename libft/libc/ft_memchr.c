/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:19:09 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:25:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cs;
	unsigned char		cc;

	if (!s)
		return (NULL);
	i = 0;
	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n && cs[i] != cc)
		i++;
	if (i < n && cs[i] == cc)
		return ((void *)&cs[i]);
	return (NULL);
}
