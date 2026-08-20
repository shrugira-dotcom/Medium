/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:53:26 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 13:58:43 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_algo(t_stack **a, t_stack **b)
{
	int     size;
	int     pos;

	while (*a)
	{
	size = ft_stack_size(*a);
	pos = find_min_pos(*a);
	simple_sort_to_b(pos, size, a, b);
	}
	while (*b)
		pa(b, a);
}

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

int	find_min_pos(t_stack *a)
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

void	simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b)
{
	if (pos >= size / 2)
	{
		pos = size - pos;
		while (pos)
		{
			rra(a);
			pos--;
		}
		pb(a, b);
	}
	else
	{
		while (pos)
		{
			ra(a);
			pos--;
		}
		pb(a, b);
	}
}
