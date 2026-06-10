/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:49:20 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/10 19:52:11 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo(t_stack a, t_stack b, int *algo, int *bench)
{
	t_bench_stats	stats;

	stats = (t_bench_stats){0};
	if (*bench == 1)
		disorder(&a, 1);
	else
		disorder(&a, 0);
	if (*algo >= 0 && *algo <= 4)
	{
		if (*algo == 1)
			sort_simple(&b, &a, &stats, bench);
		else if (*algo == 2)
			sort_medium(&b, &a, &stats, bench);
/* 		else if (*algo == 3)
			sort_complex(&a, &b, &stats, bench);
		else
			sort_adaptative(&a, &b, &stats, &algo, bench); */
	}
	if (*bench == 1)
		print_bench(algo, &stats);
}

//se chamar sort_adaptative, alterar *algo para o numero correspondente ao algoritmo chamado (mais facil para imprimir bench);