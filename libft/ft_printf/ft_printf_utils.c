/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:35:28 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/09 14:06:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (pf_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return ((int)i);
}

int	pf_putint(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += pf_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 10)
		count += pf_putint(nbr / 10);
	pf_putchar(nbr % 10 + '0');
	count++;
	return (count);
}

int	pf_putuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10)
		count += pf_putint(n / 10);
	pf_putchar(n % 10 + '0');
	count++;
	return (count);
}

int	pf_putxint(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n / 16)
		count += pf_putxint(n / 16, base);
	pf_putchar(base[n % 16]);
	count++;
	return (count);
}
