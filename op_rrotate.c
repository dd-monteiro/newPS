/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 22:35:29 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 18:29:29 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->data[0];
	stack->data[0] = stack->data[stack->top];
	i = stack->top;
	while (i > 1)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[i] = temp;
}

void	rra(t_stack *a, t_bench_stats *stats, int *bench)
{
	r_rotate(a);
	if (!*bench)
		write(1, "rra\n", 4);
	stats->op_rra++;
	stats->op_total++;
}

void	rrb(t_stack *b, t_bench_stats *stats, int *bench)
{
	r_rotate(b);
	if (!*bench)
		write(1, "rrb\n", 4);
	stats->op_rrb++;
	stats->op_total++;
}

void	rrr(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench)
{
	r_rotate(a);
	r_rotate(b);
	if (!*bench)
		write(1, "rrr\n", 4);
	stats->op_rrr++;
	stats->op_total++;
}
