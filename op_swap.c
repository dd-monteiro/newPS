/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:27:04 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 18:29:28 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
}

void	sa(t_stack *a, t_bench_stats *stats, int *bench)
{
	swap(a);
	if (!*bench)
		write(1, "sa\n", 3);
	stats->op_sa++;
	stats->op_total++;
}

void	sb(t_stack *b, t_bench_stats *stats, int *bench)
{
	swap(b);
	if (!*bench)
		write(1, "sb\n", 3);
	stats->op_sb++;
	stats->op_total++;
}

void	ss(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench)
{
	swap(a);
	swap(b);
	if (!*bench)
		write(1, "ss\n", 3);
	stats->op_ss++;
	stats->op_total++;
}
