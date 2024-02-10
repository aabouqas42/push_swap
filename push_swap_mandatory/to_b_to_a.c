/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:15:30 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 17:27:39 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_a(t_data *data)
{
	int	pos;
	int		max;

	while (data->stack_b)
	{
		max = get_max(data->stack_b)->number;
		pos = get_position(data->stack_b, max);
		if (pos <= stack_len(data->stack_b) / 2)
			while (data->stack_b->number != max)
				_rb_(data);
		else
			while (data->stack_b->number != max)
				_rrb_(data);
		_pa_(data);
	}
}

void	to_b(t_data *data)
{
	int	range;

	range = 16;
	if (stack_len(data->stack_a) >= 400)
		range *= 2;
	while (data->stack_a)
	{
		if (data->stack_a->index <= stack_len(data->stack_b))
			_pb_(data);
		else if (data->stack_a->index <= stack_len(data->stack_b) + range)
			(_pb_(data), _rb_(data));
		else
			_ra_(data);
	}
}
