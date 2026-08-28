/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:00:35 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 16:00:53 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_a(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts)
{
	int	i;

	while (size--)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b, counts);
			(*smaller)++;
		}
		else
		{
			ra(a, counts);
			(*bigger)++;
		}
	}
	i = *bigger;
	while (i--)
		rra(a, counts);
}

void	loop_b(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts)
{
	int	i;

	*smaller = 0;
	*bigger = 0;

	while (size--)
	{
		if ((*b)->value > pivot)
		{
			pa(b, a, counts);
			(*bigger)++;
		}
		else
		{
			rb(b, counts);
			(*smaller)++;
		}
	}
	i = *smaller;
	while (i--)
		rrb(b, counts);
}

int	pivot_loop(t_stack *a, int *stackar, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		key;

	stackar[0] = a->value;
	tmp = a->next;
	i = 1;
	while (i < size)
	{
		key = tmp->value;
		j = i - 1;
		while (j >= 0 && stackar[j] > key)
		{
			stackar[j + 1] = stackar[j];
			j--;
		}
		stackar[j + 1] = key;
		tmp = tmp->next;
		i++;
	}
	return (stackar[(size - 1) / 2]);
}