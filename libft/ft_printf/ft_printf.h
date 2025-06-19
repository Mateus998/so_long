/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:30:02 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/09 17:31:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	pf_putchar(unsigned char c);
int	pf_putstr(char *s);
int	pf_putint(int n);
int	pf_putuint(unsigned int n);
int	pf_putxint(unsigned int n, char *base);

#endif