/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:36:47 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/28 16:01:43 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b, int size)
{
	int	i;
	int	counts[11] = {0};

	i = 2;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			ft_error_exit();
		i++;
	}
	if (argc > 1 && strcmp(argv[1], "--simple") == 0)
		return (ft_simple_algo(a, b, counts));
	if (argc > 1 && strcmp(argv[1], "--medium") == 0)
		return (medium_algo(a, b, size, counts));
	if (argc > 1 && strcmp(argv[1], "--complex") == 0)
		return (quick_sort_a(a, b, size, counts));
	if (argc > 1 && strcmp(argv[1], "--adaptive") == 0)
		return (ft_adaptive(a, b, size, counts));
	if (argc > 1 && is_flag(argv[1]))
		ft_error_exit();
	ft_adaptive(a, b, size, counts);
}