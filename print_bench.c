/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:27:40 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/17 17:57:45 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mini_putnbr(int n)
{
	char	c;

	if (n >= 10)
		mini_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void	print_ops(t_bench_stats *stats)
{
	write(1, "[bench] sa: ", 12);
	mini_putnbr(stats->op_sa);
	write(1, " sb: ", 5);
	mini_putnbr(stats->op_sb);
	write(1, " ss: ", 5);
	mini_putnbr(stats->op_ss);
	write(1, " pa: ", 5);
	mini_putnbr(stats->op_pa);
	write(1, " pb: ", 5);
	mini_putnbr(stats->op_pb);
	write(1, "\n", 1);
	write(1, "[bench] ra: ", 12);
	mini_putnbr(stats->op_ra);
	write(1, " rb: ", 5);
	mini_putnbr(stats->op_rb);
	write(1, " rr: ", 5);
	mini_putnbr(stats->op_rr);
	write(1, " rra: ", 6);
	mini_putnbr(stats->op_rra);
	write(1, " rrb: ", 6);
	mini_putnbr(stats->op_rrb);
	write(1, " rrr: ", 6);
	mini_putnbr(stats->op_rrr);
	write(1, "\n", 1);
}

void	print_bench(int	*algo, t_bench_stats *stats)
{
	write(1, "[bench] strategy: ", 18);
	if (*algo == 1)
		write (1, "Simple / O(n2)\n", 15);
	else if (*algo == 2)
		write (1, "Medium / O(n√n)\n", 19);
	else if (*algo == 3)
		write (1, "Complex / O(n log n)\n", 21);
	else
	{
		write (1, "Adaptative / ", 13);
		if (*algo == 4)
			write (1, "O(n2)\n", 6);
		if (*algo == 5)
			write (1, "O(n√n)\n", 9);
		if (*algo == 6)
			write (1, "O(n log n)\n", 11);
	}
	write(1, "[bench] total_ops: ", 19);
	mini_putnbr(stats->op_total);
	write(1, "\n", 1);
	print_ops(stats);
}
