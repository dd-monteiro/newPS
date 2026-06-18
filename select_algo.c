/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:49:20 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/18 20:20:41 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_algo(t_stack *a)
{
	double	score;

	score = disorder(a, 0);
	if (score < 20)
		return (1);
	else if (score < 50)
		return (2);
	else
		return (3);
}

static int	sort_adaptive(t_stack *a, t_stack *b,
				t_bench_stats *stats, int *bench)
{
	int	choosen;

	choosen = choose_algo(a);
	if (choosen == 1)
	{
		sort_simple(b, a, stats, bench);
		return (4);
	}
	else if (choosen == 2)
	{
		sort_medium(b, a, stats, bench);
		return (5);
	}
/* 	else
	{
		sort_complex(&b, &a, &stats, bench);
		return (6);
	} */
	return (6); //para apagar depois de fazer o complex
}

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
			sort_complex(&b, &a, &stats, bench); */
		else
			*algo = sort_adaptive(&a, &b, &stats, bench);
	}
	if (*bench == 1)
		print_bench(algo, &stats);
}

//se chamar sort_adaptative, alterar *algo para o numero
// correspondente ao algoritmo chamado (mais facil para imprimir bench);