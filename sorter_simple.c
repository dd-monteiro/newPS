/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 00:04:24 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 21:58:12 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = i;
	while (i <= a->top)
	{
		if (a->data[i] < a->data[min])
			min = i;
		i++;
	}
	return (min);
}

static void	bring_to_top(t_stack *a, int min, t_bench_stats *stats, int *bench)
{
	while (min)
	{
		ra(a, stats, bench);
		min--;
	}
}

void	sort_simple(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int	min;

	while (a->top >= 0)
	{
		min = find_min_index(a);
		bring_to_top(a, min, stats, bench);
		pb(b, a, stats, bench);
	}
	while (b->top >= 0)
		pa(a, b, stats, bench);
}
