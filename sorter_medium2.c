/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_medium2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:49:56 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 22:35:07 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	find_chunk_size(t_stack *a)
{
	int	n;

	n = 1;
	while (1)
	{
		if ((n * n) < a->size)
			n++;
		if ((n * n) >= a->size)
			return (n);
	}
	return (n);
}

static int		*find_chunk_index(t_stack *a)
{
	int		*ranks;
	int 	i;
	int		min;
	int		j;
	int 	chunk;

	j = 0;
	min = 0;
	chunk = find_chunk_size(a);
	ranks = calloc(chunk, 4);
	if (!ranks)
		return(0);
	j = -1;
	while(++j < chunk)
	{
		min = 0;
		i = -1;
		while(i++ <= a->top)
			if (a->data[i] < a->data[min])			
				min = i;
		ranks[j] = a->data[min];
	}
	return (ranks);
}

static void bring_to_top(t_stack *b, int max, t_bench_stats *stats, int *bench)
{
	int		n;

	n = (b->top + 1) - max;
	if (max <= b->top / 2)
	{
		while (max)
		{
			rb(b, stats, bench);
			max--;
		}
	}
	else
	{
		while (n)
		{
			rrb(b, stats, bench);
			n--;
		}
	}
}

int sorter(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int max;
	int i;

	max = 0;
	while (b->top >= 0)
	{
		i = 0;
		while (i <= b->top)
		{
			if (b->data[i] > b->data[max])
				max = i;
			i++;
		}
		bring_to_top(b, max, stats, bench);
		pa(a, b, stats, bench);
	}
	return (max);
}
#include <stdio.h>

void sort_medium(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int i;
	int *ranks;
	int chunk;	
	
	chunk = find_chunk_size(a);
	while (a->top >= 0)
	{		
		i = 0;
		ranks = find_chunk_index(a);
		while (i < chunk)
		{
			if (a->data[0] == ranks[i])
				pb(b, a, stats, bench);
			else
				ra(a, stats, bench);
			i++;
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