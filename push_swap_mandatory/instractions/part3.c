/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:55 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/09 19:55:27 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_rrr_(t_data *data)
{
	t_stack	*node;

	if (stack_len(data->stack_a) < 2 || stack_len(data->stack_b) < 2)
		return ;
	node = data->stack_a;
	while (node->next->next)
		node = node->next;
	add_front(&data->stack_a, node->next);
	node->next = NULL;
	node = data->stack_b;
	while (node->next->next)
		node = node->next;
	add_front(&data->stack_b, node->next);
	node->next = NULL;
	ft_printf("rrr\n");
}
