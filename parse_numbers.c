/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:31:08 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/18 21:50:37 by dcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_a_add_back(t_stack *a, int n)
{
	if (a->size <= 0)
		return (0);
	a->top++;
	a->data[a->top] = n;
	return (1);
}

static int	has_duplicate(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->data[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_atol(char *str, long *n)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	*n = result * sign;
	return (1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	parse_split(t_stack *a, char **split)
{
	long	n;
	int		i;

	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (0);
		if (!ft_atol(split[i], &n))
			return (0);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		if (has_duplicate(a, (int)n))
			return (0);
		if (!stack_a_add_back(a, (int)n))
			return (0);
		i++;
	}
	return (1);
}

int	parse_numbers(t_stack *a, int argc, char **argv, int start)
{
	char	**split;

	while (start < argc)
	{
		split = ft_split(argv[start], ' ');
		if (!split)
			return (0);
		if (!parse_split(a, split))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		start++;
	}
	return (1);
}
