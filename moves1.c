/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:59:25 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 15:45:15 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack **ab)
{
	t_stack *first;
	t_stack *second;

	if (!*ab || !(*ab)->next)
		return ;

	first = *ab;
	second = (*ab)->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*ab = second;

}

void    sa(t_stack **a, int *counts)
{
	ft_swap(a);
	counts[SA]++;
	write(1, "sa\n", 3);
}

void    sb(t_stack **b, int *counts)
{
    ft_swap(b);
    counts[SB]++;
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b, int *counts)
{
    ft_swap(a);
    ft_swap(b);
    counts[SS]++;
    write(1, "ss\n", 3);
}
