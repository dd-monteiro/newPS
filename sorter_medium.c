/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:49:56 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/17 18:02:42 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_rank_position(int value, int *ranks, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (value == ranks[i])
			return (i);
		i++;
	}
	return (chunk);
}

static void	sort_ranks(int *ranks, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		temp = ranks[i];
		j = i - 1;
		while (j >= 0 && ranks[j] > temp)
		{
			ranks[j + 1] = ranks[j];
			j--;
		}
		ranks[j + 1] = temp;
		i++;
	}
}

static int	*find_chunk_index(t_stack *a)
{
	int	*ranks;
	int	i;

	ranks = malloc(sizeof(int) * (a->top + 1));
	if (!ranks)
		return (0);
	i = 0;
	while (i <= a->top)
	{
		ranks[i] = a->data[i];
		i++;
	}
	sort_ranks(ranks, a->top + 1);
	return (ranks);
}

static int	find_chunk_size(t_stack *a)
{
	int	n;
	int	total;

	n = 1;
	total = a->top + 1;
	while (n * n < total)
		n++;
	return (n);
}

void	sort_medium(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int	i;
	int	*ranks;
	int	chunk;	

	while (a->top >= 0)
	{
		chunk = find_chunk_size(a);
		ranks = find_chunk_index(a);
		if (!ranks)
			return ;
		while (chunk > 0)
		{
			i = find_rank_position(a->data[0], ranks, chunk);
			if (i < chunk)
			{
				pb(b, a, stats, bench);
				ranks[i] = ranks[--chunk];
			}
			else
				ra(a, stats, bench);
		}
		free(ranks);
	}
	sorter(b, a, stats, bench);
}
