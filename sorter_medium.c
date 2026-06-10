/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:27:21 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 22:07:32 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

/* void	sort_medium(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	int		min;
	int		mid;

	while (a->top >= 0)
	{
		mid = a->top / 2;
		min = find_min_index(a);
		if (min <= mid)
		{
			bring_to_top(a, min, stats, bench);
			pb(b, a, stats, bench);
		}
		else
		{
			while (min >= 0)
			{
				rra(a, stats, bench);
				min--;
			}
			pb(b, a, stats, bench);
		}
	}
	while (b->top >= 0)
		pa(a, b, stats, bench);
}
 */