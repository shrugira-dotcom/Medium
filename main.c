/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:00:23 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 17:49:45 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    stack_b=NULL;
    stack_a=NULL;
    init_stack_a(argc,argv,&stack_a);
    size = ft_stack_size(stack_a);
    execute_strategy(argc, argv, &stack_a, &stack_b,  size);
    //quick_sort_a(&stack_a,&stack_b,size);
    ft_print_stack(stack_a);
}

