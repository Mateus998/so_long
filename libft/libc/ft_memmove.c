/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:57:22 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:25:31 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned const char	*csrc;
	size_t				i;

	if (!dest || !src)
		return (NULL);
	i = n - 1;
	cdest = (unsigned char *)dest;
	csrc = (unsigned const char *)src;
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (n--)
		{
			cdest[i] = csrc[i];
			i--;
		}
	}
	return (dest);
}
