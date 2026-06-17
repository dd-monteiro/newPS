/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:58:30 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/17 17:58:16 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

static int	init_stacks(t_stack *a, t_stack *b, int size)
{
	if (!init_stack(a, size))
		return (0);
	if (!init_stack(b, size))
	{
		free(a->data);
		return (0);
	}
	return (1);
}

static int	valid_start(int argc, int start)
{
	if (argc == start || start == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		algo;
	int		bench;
	int		start;

	algo = 0;
	bench = 0;
	if (argc == 1)
		return (0);
	start = check_flags(argc, argv, &algo, &bench);
	if (!valid_start(argc, start))
		return (1);
	if (!init_stacks(&a, &b, argc - start))
		return (1);
	if (!parse_numbers(&a, argc, argv, start))
		return (parse_error(&a, &b));
	select_algo(a, b, &algo, &bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
