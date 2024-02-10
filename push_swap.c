/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 17:24:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus/push_swap_bonus.h"

int	main(int ac, char *av[])
{
	t_data	data;

	data.stack_a = NULL;
	data.input = get_stack(av);
	check_input(&data);
	init_stack(&data);
	if (stack_len(data.stack_a) < (ac - 1))
		show_msg(&data, "Error\n", -1);
	if (stack_len(data.stack_a) == 1)
		show_msg(&data, "", 0);
	is_sorted(&data);
	sort_all(&data);
	free_stack(data.stack_a);
	mem_free(data.input);
}
