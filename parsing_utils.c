/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:48:24 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 14:54:19 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **stack, char **arr)
{
	free_stack(stack);
	if (arr)
		free_string_array(arr);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi_strict(char *str, t_stack **stack, char **arr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error(stack, arr);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack, arr);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && (-result) < -2147483648))
			ft_error(stack, arr);
		i++;
	}
	return (result * sign);
}

void	check_duplicates(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = *stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
				ft_error(stack, NULL);
			compare = compare->next;
		}
		current = current->next;
	}
}
