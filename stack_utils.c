/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:36:21 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 14:44:47 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->cost = 0;
	new_node->above_median = 0;
    new_node->disorder = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_string_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


//***********************************************TO REMOVE********************************************************************
void ft_print_stack(t_stack *stack)  // TO REMOVE
{
	if (stack)
	{
		while(stack)
		{
			printf("%d \n", stack->value);
			stack = stack->next;
		}
	}
	else
	{
		printf("Stack is empty\n");
	}
}

void ft_print_index(t_stack *stack) // TO REMOVE
{
	printf("Printing index \n");
	if (stack)
	{
		while(stack)
		{
			printf("%d \n", stack->index);
			stack = stack->next;
		}
	}
	else
	{
		printf("Stack is empty\n");
	}
}
