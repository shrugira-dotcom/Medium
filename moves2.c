/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:01:51 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 15:48:15 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    pa(t_stack **b, t_stack **a, int *counts)
{
    t_stack *temp_b;
    t_stack *temp_a;

    if(!*b)
        return ;
    temp_b = *b;
    temp_a = *a;
    *b = temp_b->next;
    if (*b)
        (*b)->prev = NULL;
    *a = temp_b;
    temp_b->next = temp_a;
    temp_b->prev = NULL;
    if(temp_a)
        temp_a->prev = temp_b;
	counts[PA]++;
	write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b, int *counts)
{
    t_stack *temp_a;
    t_stack *temp_b;

    if(!*a)
        return ;
    temp_b = *b;
    temp_a = *a;
    *a = temp_a->next;
    if (*a)
        (*a)->prev = NULL;
    *b = temp_a;
    temp_a->next = temp_b;
    temp_a->prev = NULL;
    if(temp_b)
        temp_b->prev = temp_a;
	counts[PB]++;
	write(1, "pb\n", 3);
}
