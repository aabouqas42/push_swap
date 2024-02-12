/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 19:00:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_mandatory/push_swap.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	is_empty(av);
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.input = get_stack(av);
	check_input(&data);
	init_stack(&data);
	is_sorted(&data);
	sort_all(&data);
	free_stack(data.stack_a);
	free_tab(data.input);
}
