/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavascon <mavascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:21:53 by dcarneir          #+#    #+#             */
/*   Updated: 2026/06/10 19:44:11 by mavascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->data);
	stack->data = NULL;
	stack->top = -1;
	stack->size = 0;
}

int	init_stack(t_stack *stack, int size)
{
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
		return (0);
	stack->top = -1;
	stack->size = size;
	return (1);
}
