/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:19:35 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 12:46:14 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	_sa_(t_data *data)
{
	t_stack	*tmp;

	if (stack_len(data->stack_a) < 2)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = data->stack_a->next;
	data->stack_a->next = tmp;
}

void	_sb_(t_data *data)
{
	t_stack	*temp;

	if (stack_len(data->stack_b) < 2)
		return ;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	temp->next = data->stack_b->next;
	data->stack_b->next = temp;
}

void	_ss_(t_data *data)
{
	int	temp;

	if (stack_len(data->stack_a) < 2 || stack_len(data->stack_b) < 2)
		return ;
	temp = data->stack_a->next->number;
	data->stack_a->next->number = data->stack_a->number;
	data->stack_a->number = temp;
	temp = data->stack_b->next->number;
	data->stack_b->next->number = data->stack_b->number;
	data->stack_b->number = temp;
}

void	_pa_(t_data *data)
{
	t_stack	*node;

	if (data->stack_b == NULL)
		return ;
	node = data->stack_b->next;
	add_front(&data->stack_a, data->stack_b);
	data->stack_b = node;
}

void	_pb_(t_data *data)
{
	t_stack	*node;

	if (data->stack_a == NULL)
		return ;
	node = data->stack_a->next;
	add_front(&data->stack_b, data->stack_a);
	data->stack_a = node;
}
