/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:00:23 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/20 16:07:54 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc,char **argv)
{
    t_stack *a;
    t_stack *b;
    int size;

    b=NULL;
    a=NULL;
    init_stack_a(argc,argv,&a);
    size = ft_stack_size(a);

	medium_algo(&a, &b, argc -1);
	
   // execute_strategy(argc, argv, &a, &b,  size);
    //quick_sort_a(&a,&b,size);
    ft_print_stack(a);
	return (0);
}
/*
int main (int argc, char *argv[])
{

	if (argc < 2 || argv[1][0] == '\0')
		return (1);


	//ft_simple_algo(&a, &b);
	//medium_algo(&a, &b, argc -1);


	//free_stack(&a);
	//free_stack(&b);
	return (0);
}*/