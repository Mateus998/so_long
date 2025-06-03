/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:58:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/03 18:00:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int c, char **v)
{
    if (c != 2)
        error_exit("more/less then one parameter");
    input_validation(v[1]);
    ft_printf("pass\n");
    exit(0);
}