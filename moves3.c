/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:03:22 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 15:04:28 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_stack **ab)
{
    t_stack *temp;
    t_stack *tail;

    if (!(*ab) || !(*ab)->next)
        return;

    temp = *ab;
    tail = *ab;

    *ab = temp->next;
    (*ab)->prev = NULL;
    
    while (tail->next)
        tail = tail->next;

    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
}

void    ra(t_stack **a)
{
    ft_rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    ft_rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n", 3);
}
