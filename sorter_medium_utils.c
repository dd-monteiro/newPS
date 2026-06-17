/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_medium_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:02:01 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/17 18:02:38 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sorter(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
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
