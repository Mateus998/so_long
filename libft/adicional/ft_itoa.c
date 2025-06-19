/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:46 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:01:13 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ndigits(long nbr)
{
	size_t	count;

	count = 1;
	while (nbr / 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static void	begin(long *nbr, size_t *size, size_t *idx, int *sign)
{
	*size = 0;
	*sign = 0;
	*idx = 0;
	if (*nbr < 0)
	{
		*sign = 1;
		*size = 1;
		*nbr = -*nbr;
	}
	*size += ndigits(*nbr);
}

static void	fill_itoa(char *itoa, size_t idx, long nbr)
{
	size_t	i;

	i = idx;
	if (nbr / 10)
	{
		fill_itoa(itoa, --idx, nbr / 10);
	}
	itoa[i] = nbr % 10 + '0';
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	size;
	size_t	idx;
	int		sign;
	char	*itoa;

	nbr = n;
	begin(&nbr, &size, &idx, &sign);
	itoa = (char *)malloc((size + 1) * sizeof(char));
	if (itoa == NULL)
		return (NULL);
	if (sign)
	{
		itoa[0] = '-';
		idx = 1;
	}
	fill_itoa(itoa, size - 1, nbr);
	itoa[size] = '\0';
	return (itoa);
}
