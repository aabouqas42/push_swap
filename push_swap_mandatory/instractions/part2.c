/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:19:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/09 19:55:20 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_ra_(t_data *data)
{
	t_stack	*temp;

	if (stack_len(data->stack_a) < 2)
		return ;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	add_back(&data->stack_a, temp);
	ft_printf("ra\n");
}

void	_rb_(t_data *data)
{
	t_stack	*temp;

	if (stack_len(data->stack_b) < 2)
		return ;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	add_back(&data->stack_b, temp);
	ft_printf("rb\n");
}

void	_rr_(t_data *data)
{
	t_stack	*temp;

	if (stack_len(data->stack_a) < 2 || stack_len(data->stack_b) < 2)
		return ;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	add_back(&data->stack_a, temp);
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	add_back(&data->stack_b, temp);
	ft_printf("rr\n");
}

void	_rra_(t_data *data)
{
	t_stack	*node;

	if (stack_len(data->stack_a) < 2)
		return ;
	node = data->stack_a;
	while (node->next->next)
		node = node->next;
	add_front(&data->stack_a, node->next);
	node->next = NULL;
	ft_printf("rra\n");
}

void	_rrb_(t_data *data)
{
	t_stack	*node;

	if (stack_len(data->stack_b) < 2)
		return ;
	node = data->stack_b;
	while (node->next->next)
		node = node->next;
	add_front(&data->stack_b, node->next);
	node->next = NULL;
	ft_printf("rrb\n");
}
