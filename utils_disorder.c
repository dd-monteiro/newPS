/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 20:28:26 by mavascon          #+#    #+#             */
/*   Updated: 2026/06/10 15:28:05 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a, int print)
{
	int		mistakes;
	int		pairs;
	int		i;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < a->size - 1)
	{
		pairs += 1;
		if (a->data[i] > a->data[i + 1])
			mistakes += 1;
		i++;
	}
	if (print)
		print_disorder((double)mistakes / pairs * 100);
	return ((double)mistakes / pairs * 100);
}

void	print_disorder(double disorder)
{
	int		i;
	int		div;
	char	c;
	int		int_disorder;

	i = 4;
	int_disorder = disorder * 100;
	write(1, "[bench] disorder: ", 19);
	if (int_disorder == 10000)
	{
		write(1, "100.00%\n", 8);
		return ;
	}
	div = 1000;
	while (i)
	{
		c = (int_disorder / div) + '0';
		write(1, &c, 1);
		if (i == 3)
			write(1, ".", 1);
		int_disorder = int_disorder % div;
		div = div / 10;
		i--;
	}
	write(1, "%\n", 2);
}
