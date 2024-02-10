/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:46:16 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 14:14:45 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	mem_free(char **input)
{
	int	i;

	i = 0;
	if (input == NULL)
		return ;
	while (input[i])
	{
		free (input[i]);
		i++;
	}
	free (input);
}

void	free_stack(t_stack *stack)
{
	t_stack	*curr;

	if (stack == NULL)
		return ;
	while (stack)
	{
		curr = stack->next;
		free (stack);
		stack = curr;
	}
}
