/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:01:51 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 15:02:46 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    pa(t_stack **b, t_stack **a)
{
    t_stack *temp_b;
    t_stack *temp_a;

    if(!*b)
        return ;
    temp_b = *b;
    temp_a = *a;
    *b = temp_b->next;      //Assigning the pointer of second node as head
    if (*b)                 // Because temp_b->next could also be NULL
        (*b)->prev = NULL;
    *a = temp_b;            //Assigning node b as head, cant use 'b' here because its **
    temp_b->next = temp_a;
    temp_b->prev = NULL;
    if(temp_a)              //Becasue stack a could be empty
        temp_a->prev = temp_b;
	write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    t_stack *temp_b;

    if(!*a)
        return ;
    temp_b = *b;
    temp_a = *a;
    *a = temp_a->next;      //Assigning the pointer of second node as head
    if (*a)                 // Because temp_a->next could also be NULL
        (*a)->prev = NULL;
    *b = temp_a;            //Assigning node a as head, cant use 'a' here because its **
    temp_a->next = temp_b;
    temp_a->prev = NULL;
    if(temp_b)              //Becasue stack a could be empty
        temp_b->prev = temp_a;
	write(1, "pb\n", 3);
}
