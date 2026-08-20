/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:08:58 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/20 15:35:55 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	quick_sort_b(t_stack **a, t_stack **b, int size);
void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	smaller;
	int	bigger;
	int	i;
	if (size <= 1)
		return ;
	pivot = get_pivot(*a, size);
    printf("size=%d pivot=%d\n", size, pivot);
	smaller = 0;
	bigger = 0;
    if (size == 2)
	    {
		    if ((*a)->value > (*a)->next->value)
			    sa(a);
		    return ;
	    }
	while (size--)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b);
			 smaller++;
		}
		else
		{
			ra(a);
			bigger++;
		}
	}
	i = bigger;
	while (i--)
		rra(a);
	quick_sort_a(a, b, bigger);
	quick_sort_b(a, b, smaller);
}
void	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	smaller;
	int	bigger;
	int	i;
    if (size == 0)
        return;
    if (size == 1)
    {
        pa(b, a);
        return;
    }
    if (size == 2)
    {
        if ((*b)->value < (*b)->next->value)
            sb(b);
        pa(b, a);
        pa(b, a);
        return ;
    }
	pivot = get_pivot(*b, size);
    printf("size=%d pivot=%d\n", size, pivot);
	smaller = 0;
	bigger = 0;
	while (size--)
	{
		if ((*b)->value > pivot)
		{
			pa(b, a);
			bigger++;
		}
		else
		{
			rb(b);
			smaller++;
		}
	}
	i = smaller;
	while (i--)
		rrb(b);
quick_sort_a(a, b, bigger);
quick_sort_b(a, b, smaller);
}

int	get_pivot(t_stack *a, int size)
{
	int	*stackar;
	int	median;
	t_stack	*tmp;
	int	i;
	int	j;
	int	key;

	stackar = malloc(sizeof(int) * size);
	if (!stackar)
		return (0);
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
	median = stackar[(size - 1) / 2];
	free(stackar);
	return (median);
}
/*
int	find_max_val(t_stack *a, int size)
{
	int	max;

	max = a->value;
	while (--size)
	{
        a=a->next;
		if (a->value > max)
			max = a->value;
	}
	return (max);
}

int	find_min_val(t_stack *a, int size)
{
	int	min;

	min = a->value;
	while (--size)
	{
        a=a->next;
		if (a->value < min)
			min = a->value;
	}
	return (min);
}

int	get_pivot(t_stack *a, int size)
{
	long	min;
	long	max;

	min = find_min_val(a, size);
	max = find_max_val(a, size);

	return ((int)((min + max) / 2));
}
long get_avg(t_stack *a, int size)
{
	long sum;
	int sizec;

	sizec=size;
	sum=0;
	while(size--)
	{
		sum=sum+a->value;
		a=a->next;
	}
	return (sum/sizec);
}*/