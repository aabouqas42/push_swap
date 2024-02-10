/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:35:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 17:26:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*node;

	min = stack;
	node = stack->next;
	while (node)
	{
		if (node->number < min->number)
			min = node;
		node = node->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->number > max->number)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
