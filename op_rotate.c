/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 22:19:15 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 18:29:23 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	rotate(t_stack *stack)
{
	int		temp;
	int		i;

	temp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = temp;
}

void	ra(t_stack *a, t_bench_stats *stats, int *bench)
{
	rotate(a);
	if (!*bench)
		write(1, "ra\n", 3);
	stats->op_ra++;
	stats->op_total++;
}

void	rb(t_stack *b, t_bench_stats *stats, int *bench)
{
	rotate(b);
	if (!*bench)
		write(1, "rb\n", 3);
	stats->op_rb++;
	stats->op_total++;
}

void	rr(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench)
{
	rotate(a);
	rotate(b);
	if (!*bench)
		write(1, "rr\n", 3);
	stats->op_rr++;
	stats->op_total++;
}
