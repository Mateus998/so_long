/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:12:27 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:02:37 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	if (!dst || !src)
		return (0);
	i = 0;
	dstlen = 0;
	srclen = ft_strlen(src);
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	while (src[i] && dstsize > (dstlen + i + 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
