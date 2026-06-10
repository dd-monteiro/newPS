/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:20:43 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/10 19:33:33 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void sort_adaptative(t_stack *a, t_stack *b, t_bench_stats *stats, int *algo, int *bench)
{
	if (disorder(a, 0) < 20)
	{
		*algo = 4;
		sort_simple(b, a, stats, bench);
	}
	else if (disorder(a, 0) < 50)
	{
		*algo = 5;
		sort_medium(b, a, stats, bench);
	}
/* 	else
	{
		*algo = 6;
		sort_complex(&b, &a, &stats, bench);
	} */
	return ;
}

static int set_strategy(char *flag, int *algo)
{
	if (*algo != 0)
		return (0);
	if (ft_strcmp(flag, "--simple") == 0)
		*algo = 1;
	else if (ft_strcmp(flag, "--medium") == 0)
		*algo = 2;
	else if (ft_strcmp(flag, "--complex") == 0)
		*algo = 3;
	else if (ft_strcmp(flag, "--adaptive") == 0)
		*algo = 4;
	else
		return (0);
	return (1);
}

int	check_flags(int argc, char **argv, int *algo, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if (*bench == 1)
				return (-1);
			*bench = 1;
		}
		else if (!set_strategy(argv[i], algo))
			return (-1);
		i++;
	}
	return (i);
}
