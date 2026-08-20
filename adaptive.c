/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:14:20 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/20 15:44:05 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_disorder(t_stack *a, int size);

void	ft_adaptive(t_stack **a, t_stack **b, int size)
{
	double	dis;

	dis = ft_disorder(*a, size);
	if (dis < 0.2)
	{
		ft_simple_algo(a, b);
	}
	if (dis >= 0.2 && dis < 0.5)
	{
		medium_algo(a, b, size);
	}
	if (dis >= 0.5)
	{
		quick_sort_a(a, b, size);
	}
}

double	ft_disorder(t_stack *a, int size)
{
	t_stack	*i_node;
	t_stack	*j_node;
	int		mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = (long)size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0.0);
	i_node = a;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			if (i_node->value > j_node->value)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
