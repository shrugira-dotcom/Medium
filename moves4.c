/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:05:20 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 15:49:39 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reverse_rotate(t_stack **a)
{
    t_stack *last;

    if (!a || !(*a) || !(*a) ->next)
        return;

    last = *a;

    while (last ->next)
    {
        last = last ->next;
    }
    last ->prev ->next = NULL;
    last ->next = *a;
    (*a) ->prev = last;
    last -> prev = NULL;
    *a = last;
}

void    rra(t_stack **a, int *counts)
{
    ft_reverse_rotate(a);
    counts[RRA]++;
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b, int *counts)
{
    ft_reverse_rotate(b);
    counts[RRB]++;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b, int *counts)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    counts[RRR]++;
    write(1, "rrr\n", 4);
}
