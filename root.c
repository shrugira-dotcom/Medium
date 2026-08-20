/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:15:23 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 15:15:32 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ROOT

int	root(int num)
{
	int	base;
	int	k;

    base = ft_isqrt(num);
    if (num <= 20)
        k = base;
    else
        k = (base * 265) / 100;
    if (k < 1)
        k = 1;
    return (k);
}

int	ft_isqrt(int n)
{
	int	i;

	if (n < 0)
		return (0);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}