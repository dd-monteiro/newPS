/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:40:55 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 18:29:20 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	int	i;

	if (src->top < 0)
		return ;
	if (dest->top + 1 >= dest->size)
		return ;
	i = dest->top;
	while (i >= 0)
	{
		dest->data[i + 1] = dest->data[i];
		i--;
	}
	dest->data[0] = src->data[0];
	dest->top++;
	i = 0;
	while (i < src->top)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->top--;
}

void	pa(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench)
{
	push(a, b);
	if (!*bench)
		write(1, "pa\n", 3);
	stats->op_pa++;
	stats->op_total++;
}

void	pb(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench)
{
	push(b, a);
	if (!*bench)
		write(1, "pb\n", 3);
	stats->op_pb++;
	stats->op_total++;
}
