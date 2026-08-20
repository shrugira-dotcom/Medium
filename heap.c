/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:11:02 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 14:17:30 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	heap_utils(t_stack **a, int size)
{
	t_stack	**arr;
	t_stack	*tmp;
	int		i;

	if (size <= 0)
		return ;
	arr = malloc(sizeof(*arr) * size);
	if (!arr)
		return ;
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	sort_heap(arr, size);
	assign_index(arr, size);
	free (arr);
	add_pos(a);
}

void	sort_heap(t_stack **arr, int size)
{
	int		i;
	int		k;
	t_stack	*tmp;

	i = size / 2 - 1;		// Creating heap**************************
	while (i >= 0)
	{
		sift_down(arr, size, i);
		i--;
	}
	k = size - 1;
	while (k > 0)		//Deleting array*********************************
	{
		tmp = arr[k];
		arr[k] = arr[0];
		arr[0] = tmp;
		sift_down(arr, k, 0);
		k--;
	}
}

void	sift_down(t_stack **arr, int size, int i)
{
	t_stack	*tmp;
	int		left;
	int		right;
	int		largest;

	while (1)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		largest = i;
		if (left && left < size && arr[left]->value > arr[largest]->value)
			largest = left;
		if (right < size && arr[right]->value > arr[largest]->value)
			largest = right;
		if (largest == i)
			break ;
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		i = largest;
	}
}

void	assign_index(t_stack **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i]->index = i;
		i++;
	}
}

void	add_pos(t_stack	**a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}
