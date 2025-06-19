/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:56:04 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:25:23 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned const char	*csrc;
	size_t				i;

	if (!dest || !src)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned const char *)src;
	i = 0;
	while (n--)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
