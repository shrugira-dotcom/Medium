/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:53:26 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 17:57:01 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_stack_size(t_stack *ab)
{
	int count;

	count = 0;
	while (ab)
	{
		count++;
		ab = (ab) ->next;
	}
	return (count);
}
int find_min_pos(t_stack *a)
{
	t_stack     *temp;
	int         min;
	int         pos;
	int         index;

	temp = a;
	index = 0;
	pos = 0;
	min = a->value;
	while (temp)
	{
		if ((temp ->value) < min)
		{
			min = temp ->value;
			pos = index;
		}
		index++;
		temp = temp ->next;
	}
	return (pos);
}

void    simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b, int *counts)
{
	if (pos >= size/2)
	{
		pos = size - pos;
		while (pos)
		{
			rra(a, counts);
			pos--;
		}
		pb(a, b, counts);
	}
	else
	{
		while (pos)
		{
			ra(a, counts);
			pos--;
		}
		pb(a, b, counts);
	}
}

void    ft_simple_algo(t_stack **a, t_stack **b, int *counts)
{
	int     size;
	int     pos;

	while (*a)
	{
	size = ft_stack_size(*a);
	pos = find_min_pos(*a);
	simple_sort_to_b(pos, size, a, b, counts);
	}
	while (*b)
		pa(b, a, counts);
}
