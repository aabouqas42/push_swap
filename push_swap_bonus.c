/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/13 10:38:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus/push_swap_bonus.h"

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
	execute_instructions(&data);
	if (sorted(data.stack_a) && data.stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		(ft_putstr_fd("KO\n", 2), free_stack(data.stack_b));
	free_stack(data.stack_a);
	free_tab(data.input);
}
