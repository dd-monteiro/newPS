/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_medium2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:49:56 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/17 00:42:50 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	bring_to_top(t_stack *b, int max, t_bench_stats *stats, int *bench)
{
	int		n;

	n = (b->top + 1) - max;
	if (max <= b->top / 2)
	{
		while (max > 0)
		{
			rb(b, stats, bench);
			max--;
		}
	}
	else
	{
		while (n > 0)
		{
			rrb(b, stats, bench);
			n--;
		}
	}
}

static void	sorter(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int	max;
	int	i;

	while (b->top >= 0)
	{
		max = 0;
		i = 1;
		while (i <= b->top)
		{
			if (b->data[i] > b->data[max])
				max = i;
			i++;
		}
		bring_to_top(b, max, stats, bench);
		pa(a, b, stats, bench);
	}
}

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

	// encontrar os n numeros mais pequenos
	// array de tamanho n,  guarda os n valores mais pequenos

	// comparamos o top, se ele e igual a algum nr do novo array
	// = passas para o outro lado
	// iteras i ate chegar n
	// i chegou a a n , vamos dnv encontrar os n mais pequenos