/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:14:20 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 17:29:00 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive(t_stack **stack_a, t_stack **stack_b, int size,
		int *counts)
{
	double	dis;

	dis = ft_disorder(*stack_a, size);
	if (dis < 0.2)
	{
		ft_simple_algo(stack_a, stack_b, counts);
	}
	if (dis >= 0.2 && dis < 0.5)
	{
		medium_algo(stack_a, stack_b, size, counts);
	}
	if (dis >= 0.5)
	{
		quick_sort_a(stack_a, stack_b, size, counts);
	}
}

double	ft_disorder(t_stack *stack_a, int size)
{
	t_stack	*i_node;
	t_stack	*j_node;
	int		mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = (long)size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0.0);
	i_node = stack_a;
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