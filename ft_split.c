/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:00:31 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/18 21:08:24 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	if (!*s)
		return (0);
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

static void	free_all(char **res, int n)
{
	while (n >= 0)
		free(res[n--]);
	free(res);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_fill_split(char **res, char const *s, char c)
{
	int	i;
	int	wordlen;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wordlen = ft_wordlen(s, c);
			res[i] = ft_substr(s, 0, wordlen);
			if (!res[i])
			{
				free_all(res, i - 1);
				return (0);
			}
			i++;
			s += wordlen;
		}
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	return (ft_fill_split(res, s, c));
}
