/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:57:19 by sradhakr          #+#    #+#             */
/*   Updated: 2026/08/19 14:58:01 by sradhakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

size_t	counter(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*get_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split(char **d, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(d[i]);
		i++;
	}
	free(d);
}

int	fill_split(char **d, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		d[j] = get_word(s, start, i);
		if (d[j] == NULL)
			return (free_split(d, j), 0);
		j++;
	}
	d[j] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**d;

	if (s == NULL)
		return (NULL);
	d = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (d == NULL)
		return (NULL);
	if (!fill_split(d, s, c))
	{
		return (NULL);
	}
	return (d);
}
