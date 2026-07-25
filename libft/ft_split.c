/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:40:17 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/17 18:40:28 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
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

static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
}

static int	add_word(char **arr, char const *s, size_t len, size_t w)
{
	size_t	i;

	arr[w] = malloc(len + 1);
	if (!arr[w])
	{
		free_all(arr, w);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		arr[w][i] = s[i];
		i++;
	}
	arr[w][i] = '\0';
	return (1);
}

static char	**fill(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			if (!add_word(arr, s + i, len, w++))
				return (NULL);
			i += len;
		}
	}
	arr[w] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill(arr, s, c));
}
