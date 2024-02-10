/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:52:32 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/08 16:01:40 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data *data)
{
	t_stack	*max;
	int		pos;

	max = get_max(data->stack_a);
	pos = get_position(data->stack_a, max->number);
	if (pos == 1)
		_ra_(data);
	if (pos == 2)
		_rra_(data);
	if (!sorted(data->stack_a))
		_sa_(data);
}

void	sort_4(t_data *data)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = get_min(data->stack_a);
	pos = get_position(data->stack_a, min->number);
	size = stack_len(data->stack_a);
	if (pos <= (size / 2))
	{
		while (data->stack_a->number != min->number)
			_ra_(data);
	}
	else
	{
		while (data->stack_a->number != min->number)
			_rra_(data);
	}
	_pb_(data);
	sort_3(data);
	_pa_(data);
}

void	sort_5(t_data *data)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = get_min(data->stack_a);
	pos = get_position(data->stack_a, min->number);
	size = stack_len(data->stack_a);
	if (pos <= (size / 2))
	{
		while (data->stack_a->number != min->number)
			_ra_(data);
	}
	else
	{
		while (data->stack_a->number != min->number)
			_rra_(data);
	}
	_pb_(data);
	sort_4(data);
	_pa_(data);
}

void	sort_all(t_data *data)
{
	if (stack_len(data->stack_a) == 2)
	{
		_sa_(data);
		return ;
	}
	if (stack_len(data->stack_a) == 3)
	{
		sort_3(data);
		return ;
	}
	if (stack_len(data->stack_a) == 4)
	{
		sort_4(data);
		return ;
	}
	if (stack_len(data->stack_a) == 5)
	{
		sort_5(data);
		return ;
	}
	to_b(data);
	to_a(data);
}
