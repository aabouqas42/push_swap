/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:44:48 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 13:35:54 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*creat_new_node(int number)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **head, t_stack *new_node)
{
	t_stack	*node;

	node = *head;
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	if (node == NULL)
	{
		*head = new_node;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new_node;
}

void	add_front(t_stack **head, t_stack *new_node)
{
	t_stack	*node;

	if (new_node == NULL)
		return ;
	node = *head;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = *head;
	(*head) = new_node;
}

int	sorted(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
