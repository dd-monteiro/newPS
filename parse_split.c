/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:48:36 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/18 22:11:23 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(int argc, char **argv, int start)
{
	int	count;
	int	j;

	count = 0;
	while (start < argc)
	{
		j = 0;
		while (argv[start][j])
		{
			while (argv[start][j] == ' ')
				j++;
			if (argv[start][j])
				count++;
			while (argv[start][j] && !(argv[start][j] == ' '))
				j++;
		}
		start++;
	}
	return (count);
}
