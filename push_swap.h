/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:33:50 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 22:08:26 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*data;
	int		top;
	int		size;
}			t_stack;

typedef struct s_bench_stats
{
	int	op_sa;
	int	op_sb;
	int	op_ss;
	int	op_pa;
	int	op_pb;
	int	op_ra;
	int	op_rb;
	int	op_rr;
	int	op_rra;
	int	op_rrb;
	int	op_rrr;
	int	op_total;
}			t_bench_stats;

void			pa(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench);
void			pb(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench);
void			ra(t_stack *a, t_bench_stats *stats, int *bench);
void			rb(t_stack *b, t_bench_stats *stats, int *bench);
void			rr(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench);
void			rra(t_stack *a, t_bench_stats *stats, int *bench);
void			rrb(t_stack *b, t_bench_stats *stats, int *bench);
void			rrr(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench);
void			sa(t_stack *a, t_bench_stats *stats, int *bench);
void 			sb(t_stack *b, t_bench_stats *stats, int *bench);
void 			ss(t_stack *a, t_stack *b, t_bench_stats *stats, int *bench);

int				check_flags(int argc, char **argv, int *algo, int *bench);
int				init_stack(t_stack *stack, int size);
int				parse_numbers(t_stack *a, int argc, char **argv, int start);
int				ft_printf(const char *format, ...);
void			free_stack(t_stack *stack);
int				find_min_index(t_stack *a);

void			select_algo(t_stack a, t_stack b, int *algo, int *bench);
void			sort_simple(t_stack *b, t_stack *a,
					t_bench_stats *stats, int *bench);
void sort_medium(t_stack *b, t_stack *a, t_bench_stats *stats, int *bench);

	void print_bench(int *algo, t_bench_stats *stats);

double			disorder(t_stack *a, int print);
void			print_disorder(double disorder);

#endif
