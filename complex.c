/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:08:58 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 17:34:16 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size, int *counts)
{
	int	pivot;
	int	smaller;
	int	bigger;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, counts);
		return ;
	}
	pivot = get_pivot(*a, size);
	smaller = 0;
	bigger = 0;
	loop_a(a, b, pivot, size, &smaller, &bigger, counts);
	quick_sort_a(a, b, bigger, counts);
	quick_sort_b(a, b, smaller, counts);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size, int *counts)
{
	int	pivot;
	int	smaller;
	int	bigger;

	if (size == 0)
		return ;
	if (size == 1)
	{
		pa(b, a, counts);
		return ;
	}
	if (size == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(b, counts);
		pa(b, a, counts);
		pa(b, a, counts);
		return ;
	}
	pivot = get_pivot(*b, size);
	loop_b(a, b, pivot, size, &smaller, &bigger, counts);
	quick_sort_a(a, b, bigger, counts);
	quick_sort_b(a, b, smaller, counts);
}

int	get_pivot(t_stack *a, int size)
{
	int	*stackar;
	int	median;

	stackar = malloc(sizeof(int) * size);
	if (!stackar)
		return (0);
	median = pivot_loop(a, stackar, size);
	free(stackar);
	return (median);
}
