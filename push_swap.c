/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:58:30 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/10 19:48:07 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stacks(t_stack *a, t_stack *b);


static int parse_error(t_stack *a, t_stack *b)
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
	printf("size a: %i\n top a: %i\n", a.size, a.top);
	print_stacks(&a, &b);
	select_algo(a, b, &algo, &bench);
	print_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

static void print_stacks(t_stack *a, t_stack *b)
{
	int i;
	int max;

	max = a->top;
	if (b->top > max)
		max = b->top;

	printf("----\n");
	printf("a  b\n\n");

	i = 0;
	while (i <= max)
	{
		if (i <= a->top)
			printf("%i", a->data[i]);
		else
			printf(" ");

		printf("  ");

		if (i <= b->top)
			printf("%i", b->data[i]);

		printf("\n");
		i++;
	}
	printf("----\n");
}